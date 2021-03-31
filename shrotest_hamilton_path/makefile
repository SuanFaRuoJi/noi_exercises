CC = g++
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = shrotest_hamilton_path

shrotest_hamilton_path: shrotest_hamilton_path.cpp
	$(CC) -o shrotest_hamilton_path shrotest_hamilton_path.cpp

test: shrotest_hamilton_path
	./shrotest_hamilton_path < test_data

clean:
	rm -rf *.o shrotest_hamilton_path
