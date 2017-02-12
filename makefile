#compiler used
CC = g++
#language version
CV = -std=c++14
#dependencies
FILES = book.h patron.h date.h library.h std_lib_facilities.h book.cpp patron.cpp date.cpp library.cpp main.cpp
#executable name
OUT_EXE = Library.exe

#target definition
myLib: $(FILES)
		$(CC) $(CV) -o $(OUT_EXE) $(FILES)
