#ifndef ROCKSDB_C_H
#define ROCKSDB_C_H

#ifdef __cplusplus
extern "C"
#endif
void* rocksdb_open(const char *name);

#ifdef __cplusplus
extern "C"
#endif
int rocksdb_get(void *db, const char *key, char **value, int *value_size);

#ifdef __cplusplus
extern "C"
#endif
int rocksdb_put(void *db, const char *key, const char *value);

#ifdef __cplusplus
extern "C"
#endif
int rocksdb_delete(void *db, const char *key);

#ifdef __cplusplus
extern "C"
#endif
int rocksdb_close(void *db);

#endif
