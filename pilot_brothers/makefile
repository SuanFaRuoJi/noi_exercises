CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = pilot_brothers

pilot_brothers: pilot_brothers.cpp
	$(CC) $(C_STANDARD) -o pilot_brothers.out pilot_brothers.cpp

test: pilot_brothers
	./pilot_brothers.out < test_data

clean:
	rm -rf *.o pilot_brothers.out
