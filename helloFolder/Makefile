all: helloWorld

helloWorld: helloWorld.o
	g++ -o helloWorld.o -shared libmy_lib.so

helloWorld.o: 
	g++ -o helloWorld.cpp -shared -fPIC hello.cpp
