CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = tallest_cow

tallest_cow: tallest_cow.cpp
	$(CC) $(C_STANDARD) -o tallest_cow.out tallest_cow.cpp

test: tallest_cow
	./tallest_cow < test_data

clean:
	rm -rf *.o tallest_cow
