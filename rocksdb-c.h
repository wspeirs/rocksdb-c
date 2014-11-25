#ifndef ROCKSDB_C_H
#define ROCKSDB_C_H

#ifdef __cplusplus
extern "C"
#endif
void* open(const char *name);

#ifdef __cplusplus
extern "C"
#endif
bool get(void *db, const char *key, char **value, int *value_size);

#ifdef __cplusplus
extern "C"
#endif
bool put(void *db, const char *key, const char *value);

#ifdef __cplusplus
extern "C"
#endif
bool del(void *db, const char *key);

#ifdef __cplusplus
extern "C"
#endif
bool close(void *db);

#endif
