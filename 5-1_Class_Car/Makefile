all: 5-1_Class_Car_A

vehicle_a.o: vehicle_a.cpp vehicle_a.h
	g++ -c vehicle_a.cpp -o vehicle_a.o

5-1_Class_Car_A: vehicle_a.o 5-1_Class_Car_A.cpp
	g++ vehicle_a.o 5-1_Class_Car_A.cpp -o 5-1_Class_Car_A
	echo "type ./5-1_Class_Car_A to run program"

clean: 
	rm vehicle_a.o 5-1_Class_Car_A
