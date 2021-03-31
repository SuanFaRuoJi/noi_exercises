CC = g++
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = floating_point_multiplication

floating_point_multiplication:
	$(CC) -o floating_point_multiplication floating_point_multiplication.cpp

test: floating_point_multiplication
	./floating_point_multiplication < test_data

clean:
	rm -rf *.o floating_point_multiplication
