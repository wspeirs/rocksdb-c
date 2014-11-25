GPP   = /usr/bin/g++
GCC   = /usr/bin/gcc
FLAGS = -W -O3 -std=gnu++11 -fPIC
LIBS  = -lrocksdb
INC   = -I../rocksdb/include
EXEC  = librocksdb-c.so

all: rocksdb-c.o 
	$(GPP) $(FLAGS) -shared *.o $(LIBS) -o $(EXEC)

rocksdb-c.o: rocksdb-c.cpp rocksdb-c.h
	$(GPP) -c $(FLAGS) $(INC) rocksdb-c.cpp

clean:
	rm *~ *.o $(EXEC) 2>/dev/null
