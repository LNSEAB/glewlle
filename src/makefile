TARGET=../glewlle.hpp
SRC=../glext.h ../wglext.h ../glxext.h

$(TARGET): $(SRC) license.txt include.pp glewlle_include.pp glewlle_make_header.py
	python glewlle_make_header.py
