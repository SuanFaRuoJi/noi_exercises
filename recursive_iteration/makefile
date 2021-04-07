CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = recursive_iteration

recursive_iteration: recursive_iteration.cpp
	$(CC) $(C_STANDARD) -o recursive_iteration.out recursive_iteration.cpp

test: recursive_iteration
	./recursive_iteration.out < test_data

clean:
	rm -rf *.o recursive_iteration.out
