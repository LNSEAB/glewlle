import sys
import re
		
reg_prototype = re.compile( '^GLAPI (\w+) APIENTRY ([\w \*]+) \((.*)\);' )
reg_arg_name = re.compile( ' \**(\w+)$' )

def write_file(src_f, dst_f) :
	for i in src_f :
		dst_f.write( i )

def parse_functions(src_f) :
	funcs = []
	for i in src_f :
		m = reg_prototype.match( i )
		if not m :
			continue
		funcs.append( [m.group( 1 ), m.group( 2 ), m.group( 3 ).split( ',' )] );
	return funcs

def arg_name(arg) :
	m = reg_arg_name.search( arg )
	if m :
		return m.group( 1 )
	return ''

def write_function(func, dst_f) :
	arguments = ', '.join( func[2] )

	names = []
	for i in func[2] :
		n = arg_name( i )
		if n != '' :
			names.append( n )
	if func[0] == 'void' :
		ret = ''
	else :
		ret = 'return '

	dst_f.write( \
			'inline ' + func[0] + ' ' + func[1] + '(' + arguments + ')\n{\n' \
			+ '\ttypedef ' + func[0] + ' (*proc_type)(' + arguments + ');\n' \
			+ '\tstatic proc_type func_ptr = reinterpret_cast<proc_type>( wglGetProcAddress( "' + func[1] + '" ) );\n' \
			+ '\tif( !func_ptr ) { throw std::runtime_error( "glewlle error : ' + func[1] + '" ); }\n' \
			+ '\t' + ret + '(*func_ptr)( ' + ', '.join( names ) + ' );\n' \
			+ '}\n\n' )
	
def main() :
	glewlle = open( '../glewlle.hpp', 'w' )

	with open( 'license.txt', 'r' ) as f :
		write_file( f, glewlle )
	glewlle.write( '\n' )

	include_guard = 'GLEWLLE_HPP_'
	glewlle.write( '#ifndef ' + include_guard + '\n' )
	glewlle.write( '#define ' + include_guard + '\n\n' )

	with open( 'include.pp', 'r' ) as f :
		write_file( f, glewlle )
	glewlle.write( '\n' )

	with open( '../glext.h', 'r' ) as f :
		funcs = parse_functions( f )
		for i in funcs :
			write_function( i, glewlle )
	glewlle.write( '\n' )
	
	glewlle.write( '#endif // ' + include_guard + '\n' )

main()
