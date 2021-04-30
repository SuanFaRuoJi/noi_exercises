CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = best_cow_fences

best_cow_fences: best_cow_fences.cpp
	$(CC) $(C_STANDARD) -o best_cow_fences.out best_cow_fences.cpp

test: best_cow_fences
	./best_cow_fences.out < test_data

clean:
	rm -rf *.o best_cow_fences.out
