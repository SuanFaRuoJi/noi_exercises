CC = g++
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = laser_bomb

laser_bomb: laser_bomb.cpp
	$(CC) -o laser_bomb.out laser_bomb.cpp

test: laser_bomb
	./laser_bomb.out < test_data

clean:
	rm -rf *.o laser_bomb.out
