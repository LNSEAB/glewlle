import sys
import re

re_proto = re.compile( '^(?:GLAPI|extern) +([\w \*]+) (?:APIENTRY )?([\w \*]+) \((.*)\);' )
re_arg = re.compile( ' \**(\w+)$' )
re_header_if = re.compile( '#ifdef (_VL_H|_DM_BUFFER_H_)' )
re_header_end = re.compile( '#endif (/\* _VL_H \*/|/\* _DM_BUFFER_H_ \*/)' )

def get_arguments(args) :
	m = re_arg.search( args )
	if m :
		return m.group( 1 )
	return ''

def return_statement(ret_type) :
	if ret_type == 'void' :
		return ''
	else :
		return 'return '

def parse_names(args) :
	names = []
	for i in args :
		n = get_arguments( i )
		if n != '' :
			names.append( n )
	return names

def write_text_file(src_name, dest_file) :
	with open( src_name, 'r' ) as src_file :
		for i in src_file :
			dest_file.write( i )
		dest_file.write( '\n' )

def write_function(func, dest_file) :
	args = ','.join( func[2] )
	names = parse_names( func[2] )
	ret = return_statement( func[0] )
	dest_file.write( \
			'inline ' + func[0] + ' ' + func[1] + '(' + args + ')\n{\n' \
			+ '\ttypedef ' + func[0] + ' (*proc_type)(' + args + ');\n' \
			+ '\tstatic proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "' + func[1] + '" ) );\n' \
			+ '\tif( !func_ptr ) { throw std::runtime_error( "glewlle error : ' + func[1] + '" ); }\n' \
			+ '\t' + ret + '(*func_ptr)( ' + ', '.join( names ) + ' );\n' \
			+ '}\n\n' )

def parse_functions(src_file, dest_file) :
	flg = 0
	for i in src_file :
		m = re_header_if.match( i )
		if m :
			dest_file.write( i )
			flg = 1
			continue
		m = re_header_end.match( i )
		if m :
			dest_file.write( i )
			flg = 0
			continue
		m = re_proto.match( i )
		if not m :
			continue
		write_function( [m.group( 1 ), m.group( 2 ), m.group( 3 ).split( ',' )], dest_file );

def include_guard_str(name) :
	s = name.replace( '../', '' )
	s = s.upper()
	s = s.replace( '.', '_' )
	return s + '_'

def make_file(name, src_file, file_list) :
	dest_file = open( name, 'w' )
	dest_file.write( '// ' + name.replace( '../', '' ).replace( '.hpp', '' ) + '\n' )
	write_text_file( 'copy.txt', dest_file )
	guard = include_guard_str( name )

	dest_file.write( \
			'#ifndef ' + guard + '\n' \
			+ '#define ' + guard + '\n\n' );
	for i in file_list :
		write_text_file( i, dest_file )
	dest_file.write( '#include <' + src_file.replace( '../', '' ) + '>\n\n' );

	with open( src_file, 'r' ) as f :
		parse_functions( f, dest_file )
	dest_file.write( '\n' )
	dest_file.write( '#endif // ' + guard + '\n' )

def main() :
	make_file( '../glewlle.hpp', '../glext.h', ['include.pp'] )
	make_file( '../glewlle_wgl.hpp', '../wglext.h', ['glewlle_include.pp'] )
	make_file( '../glewlle_glx.hpp', '../glxext.h', ['glewlle_include.pp'] )

main()
