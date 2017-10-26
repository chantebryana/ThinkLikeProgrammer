all: 200dash_main

200dash.o: 200dash.cpp 200dash.h
	mkdir -p bin
	g++ -c 200dash.cpp -o bin/200dash.o

200dash_main: 200dash.o 200dash_main.cpp
	g++ bin/200dash.o 200dash_main.cpp -o bin/200dash_main
	echo "type ./bin/200dash_main to run program"

#CE: run 'make clean' in terminal to execute these commands:
clean: 
	rm bin/*
	rmdir bin

