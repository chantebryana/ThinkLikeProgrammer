all: strings_a

strings.o: strings.cpp strings.h
	mkdir -p bin
	g++ -c strings.cpp -o bin/strings.o

strings_a: strings.o strings_a.cpp
	g++ bin/strings.o strings_a.cpp -o bin/strings_a
	echo "type ./bin/strings_a to run program"

clean: 
	rm bin/*
	rmdir bin
