all: vehicle_main

vehicle.o: vehicle.cpp vehicle.h
	mkdir -p bin
	g++ -c vehicle.cpp -o bin/vehicle.o

vehicle_main: vehicle.o vehicle_main.cpp
	g++ bin/vehicle.o vehicle_main.cpp -o bin/vehicle_main
	echo "type ./bin/vehicle_main to run program"

#CE: run 'make clean' in terminal to execute these commands
clean: 
	rm bin/* 
	rmdir bin
	#rm vehicle.o vehicle_main
