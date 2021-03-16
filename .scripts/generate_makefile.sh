#!/bin/bash

cat << END
CC = g++
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = $1

$1:
	\$(CC) -o $1 $1.cpp

clean:
	rm -rf *.o $1
END
