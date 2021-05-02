CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = inc_dec_sequence

inc_dec_sequence: inc_dec_sequence.cpp
	$(CC) $(C_STANDARD) -o inc_dec_sequence.out inc_dec_sequence.cpp

test: inc_dec_sequence
	./inc_dec_sequence.out < test_data

clean:
	rm -rf *.o inc_dec_sequence.out
