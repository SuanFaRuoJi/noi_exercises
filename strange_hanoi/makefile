CC = g++
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = strange_hanoi

strange_hanoi: strange_hanoi.cpp
	$(CC) -o strange_hanoi.out strange_hanoi.cpp

test: strange_hanoi
	./strange_hanoi < test_data

clean:
	rm -rf *.o strange_hanoi
