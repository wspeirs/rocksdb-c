GPP   = /usr/bin/g++
GCC   = /usr/bin/gcc
FLAGS = -W -g -std=gnu++11 -fPIC
LIBS  = -lrocksdb
INC   = -I../rocksdb/include
EXEC  = rocksdb-c.so

all: rocksdb-c.o 
	$(GPP) $(FLAGS) -shared *.o $(LIBS) -o lib$(EXEC)

test: test.c
	$(GCC) -ggdb test.c -o test -L. -lrocksdb-c

rocksdb-c.o: rocksdb-c.cpp rocksdb-c.h
	$(GPP) -c $(FLAGS) $(INC) rocksdb-c.cpp

clean:
	rm *~ *.o *.so test 2>/dev/null
