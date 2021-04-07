CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = recrusive_permutation

recrusive_permutation: recrusive_permutation.cpp
	$(CC) $(C_STANDARD) -o recrusive_permutation.out recrusive_permutation.cpp

test: recrusive_permutation
	./recrusive_permutation.out < test_data

clean:
	rm -rf *.o recrusive_permutation.out
