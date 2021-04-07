CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = recursive_combination

recursive_combination: recursive_combination.cpp
	$(CC) $(C_STANDARD) -o recursive_combination.out recursive_combination.cpp

test: recursive_combination
	./recursive_combination.out < test_data

clean:
	rm -rf *.o recursive_combination.out
