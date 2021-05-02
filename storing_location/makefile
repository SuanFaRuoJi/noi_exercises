CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = storing_location

storing_location: storing_location.cpp
	$(CC) $(C_STANDARD) -o storing_location.out storing_location.cpp

test: storing_location
	./storing_location.out < test_data

clean:
	rm -rf *.o storing_location.out
