#include "rocksdb-c.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv)
{
  void* db = rocksdb_open("/tmp/test");
  char *value;
  int value_size;

  if(db == NULL) {
    printf("DB is NULL\n");
    return -1;
  } else {
    printf("DB opened\n");
  }

  if(!rocksdb_put(db, "key", "value")) {
    printf("PUT didn't work\n");
    return -1;
  } else {
    printf("PUT worked!\n");
  }

  if(!rocksdb_get(db, "key", &value, &value_size)) {
    printf("GET didn't work\n");
    return -1;
  } else {
    printf("GET worked!\n");
  }

  printf("Got value: %s\n", value);

  free(value);

  if(!rocksdb_delete(db, "key")) {
    printf("DEL didn't work\n");
    return -1;
  }
  
  if(!rocksdb_get(db, "key", &value, &value_size)) {
    printf("GET didn't work\n");
    return -1;
  } else {
    printf("GET worked!\n");
  }

  rocksdb_close(db);

  return 0;
}