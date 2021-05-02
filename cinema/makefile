CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = cinema

cinema: cinema.cpp
	$(CC) $(C_STANDARD) -o cinema.out cinema.cpp

test: cinema
	./cinema.out < test_data

clean:
	rm -rf *.o cinema.out
