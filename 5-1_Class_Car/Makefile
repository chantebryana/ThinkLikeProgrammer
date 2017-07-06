all: 5-1_Class_Car_A

vehicle_a.o: vehicle_a.cpp vehicle_a.h
	mkdir -p bin
	g++ -c vehicle_a.cpp -o bin/vehicle_a.o

5-1_Class_Car_A: vehicle_a.o 5-1_Class_Car_A.cpp
	g++ bin/vehicle_a.o 5-1_Class_Car_A.cpp -o bin/5-1_Class_Car_A
	echo "type ./bin/5-1_Class_Car_A to run program"

clean: 
	rm bin/* 
	rmdir bin
	#rm vehicle_a.o 5-1_Class_Car_A
