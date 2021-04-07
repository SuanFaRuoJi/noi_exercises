CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = sumdiv

sumdiv: sumdiv.cpp
	$(CC) $(C_STANDARD) -o sumdiv.out sumdiv.cpp

test: sumdiv
	./sumdiv.out < test_data

clean:
	rm -rf *.o sumdiv.out
