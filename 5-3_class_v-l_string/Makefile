all: string_main

string.o: string.cpp string.h
	mkdir -p bin
	g++ -c string.cpp -o bin/string.o

string_main: string.o string_main.cpp
	g++ bin/string.o string_main.cpp -o bin/string_main
	echo "type ./bin/string_main to run program"

clean: 
	rm bin/*
	rmdir bin

