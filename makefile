CXX=g++

PATH = /home/nazk/prs/cppcours/vcpkg/installed/x64-linux

CXXflags = -I$(PATH)/include

LDflags = -L$(PATH)/lib

LDlibs = -lopengl32 -lgdi32

game: main.cpp 
	g++ main.cpp -o game $(CXXflags) $(LDflags) $(LDlibs)