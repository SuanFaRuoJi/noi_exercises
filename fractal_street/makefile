CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = fractal_street

fractal_street: fractal_street.cpp
	$(CC) $(C_STANDARD) -o fractal_street.out fractal_street.cpp

test: fractal_street
	./fractal_street.out < test_data

clean:
	rm -rf *.o fractal_street.out
