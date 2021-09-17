CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = qixiji

qixiji: qixiji.cpp
	$(CC) $(C_STANDARD) -o qixiji.out qixiji.cpp

test: qixiji
	./qixiji.out < test_data

clean:
	rm -rf *.o qixiji.out
