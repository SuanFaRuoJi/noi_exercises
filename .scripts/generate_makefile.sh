#!/bin/bash

cat << END
CC = g++
C_STANDARD = -std=c++11
OBJECT_FLAG = -c
TARGET = $1

$1: $1.cpp
	\$(CC) \$(C_STANDARD) -o $1.out $1.cpp

test: $1
	./$1.out < test_data

clean:
	rm -rf *.o $1.out
END
