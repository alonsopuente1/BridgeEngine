main: main.o Window.o
	gcc main.o Window.o -o main
	
main.o: main.cpp
	gcc -c main.cpp
	
window.o: Window.cpp Window.h
	gcc -c window.cpp