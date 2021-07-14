CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = editor

editor: editor.cpp
	$(CC) $(C_STANDARD) -o editor.out editor.cpp

test: editor
	./editor.out < test_data

clean:
	rm -rf *.o editor.out
