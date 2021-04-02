CC = g++
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = switches

switches: switches.cpp
	$(CC) -o switches.out switches.cpp

test: switches
	./switches < test_data

clean:
	rm -rf *.o switches
