#include <iostream>
#include <musket/musket.hpp>
#include <musket/opengl.hpp>
#include "../glewlle.hpp"

class triangle
{
	GLuint vs_, fs_;
	GLuint prog_;
	GLuint buf_;
	
public:
	triangle() :
		vs_( glCreateShader( GL_VERTEX_SHADER ) ),
		fs_( glCreateShader( GL_FRAGMENT_SHADER ) ),
		prog_( glCreateProgram() )
	{
		char const* vs_src = R"(
			#version 330
			in vec3 Position;

			void main()
			{
				gl_Position = vec4( Position, 1.0 );
			}
		)";

		char const* fs_src = R"(
			#version 330
			out vec3 fragColor;

			void main()
			{
				fragColor = vec4( 1.0, 0.0, 0.0, 1.0 );
			}
		)";

		GLchar const** vs_str = &vs_src;
		GLchar const** fs_str = &fs_src;
		GLint const vs_sz = std::strlen( vs_src );
		GLint const fs_sz = std::strlen( fs_src );
		glShaderSource( vs_, 1, vs_str, &vs_sz );
		glShaderSource( fs_, 1, fs_str, &fs_sz );

		glCompileShader( vs_ );
		glCompileShader( fs_ );

		glAttachShader( prog_, vs_ );
		glAttachShader( prog_, fs_ );

		glLinkProgram( prog_ );
		glUseProgram( prog_ );

		GLfloat pt[9] = {
			 0.0f,  1.0f, 0.0f,
			-1.0f, -1.0f, 0.0f,
			 1.0f, -1.0f, 0.0f
		};

		glGenBuffers( 1, &buf_ );
		glBindBuffer( GL_ARRAY_BUFFER, buf_ );
		glBufferData( GL_ARRAY_BUFFER, sizeof( pt ), pt, GL_STATIC_DRAW );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
	}

	~triangle()
	{
		if( buf_ ) {
			glDeleteBuffers( 1, &buf_ );
		}
		if( prog_ ) {
			glDeleteProgram( prog_ );
		}
		if( vs_ ) {
			glDetachShader( prog_, vs_ );
			glDeleteShader( vs_ );
		}
		if( fs_ ) {
			glDetachShader( prog_, fs_ );
			glDeleteShader( fs_ );
		}
	}
	
	void render() const 
	{
		glEnableVertexAttribArray( 0 );
		glBindBuffer( GL_ARRAY_BUFFER, buf_ );
		glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, nullptr );
		glDrawArrays( GL_TRIANGLES, 0, 3 );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
		glDisableVertexAttribArray( 0 );
	}
};

int main()
{
	typedef musket::point_t<int> point_type;
	typedef musket::size_t<unsigned int> size_type;

	try {
		auto const wnd = musket::make_widget<musket::window<>>(
				point_type( 0, 0 ), size_type( 640, 480 ), "glewlle test" );
		auto const gl = musket::make_widget<musket::opengl_panel<>>(
				wnd, point_type( 0, 0 ), size_type( 640, 480 ), musket::opengl::z_depth( 24 ) );
		
		musket::opengl::call( gl, glClearColor, 0, 0, 0.3, 0 );
		musket::opengl::call( gl, glClearDepth, 1.0f );
		triangle tri;

		musket::show( wnd );

		musket::run<musket::nowait_event>( [&gl, &tri](musket::run_state) {
			musket::opengl::call( gl, glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
			tri.render();
			musket::opengl::swap_buffers( gl );
		} );
	}
	catch( std::exception const&& e ) {
		std::cout << e.what() << std::endl;
	}
}
