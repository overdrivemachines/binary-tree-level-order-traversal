
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

binary-tree-level-order-traversal: binary-tree-level-order-traversal.o
	$(CC) $(CFLAGS) -o binary-tree-level-order-traversal binary-tree-level-order-traversal.o

binary-tree-level-order-traversal.o: binary-tree-level-order-traversal.cpp
	$(CC) $(CFLAGS) -c binary-tree-level-order-traversal.cpp

clean:
	rm -rf binary-tree-level-order-traversal binary-tree-level-order-traversal.o
