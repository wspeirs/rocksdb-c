#include "rocksdb-c.h"
#include "rocksdb/db.h"
#include <string>

extern "C" void* open(const char *name)
{
    rocksdb::DB* db;
    std::string name_str(name);
    
    rocksdb::Options options;
    
    options.create_if_missing = true;    
    
    rocksdb::Status status = rocksdb::DB::Open(options, name_str, &db);
    
    if(status.ok()) {
        return db;
    } else {
        return NULL;
    }
}

extern "C" bool get(void *db, const char *key, char **value, int *value_size)
{
    rocksdb::DB* dbh = reinterpret_cast<rocksdb::DB*>(db);
    rocksdb::Slice key_slice(key);
    std::string value_str;
    
    rocksdb::Status status = dbh->Get(rocksdb::ReadOptions(), key_slice, &value_str);
    
    *value_size = value_str.size() + 1;
    
    *value = reinterpret_cast<char*>(malloc(value_str.size()+1));
    
    memcpy(*value, value_str.c_str(), value_str.size());    
    
    return status.ok();
}

extern "C" bool put(void *db, const char *key, const char *value)
{
    rocksdb::DB* dbh = reinterpret_cast<rocksdb::DB*>(db);
    rocksdb::Slice key_slice(key);
    rocksdb::Slice value_slice(value);
 
    rocksdb::Status status = dbh->Put(rocksdb::WriteOptions(), key_slice, value_slice);
    
    return status.ok();
}

extern "C" bool del(void *db, const char *key)
{
    rocksdb::DB* dbh = reinterpret_cast<rocksdb::DB*>(db);
    rocksdb::Slice key_slice(key);
    
    rocksdb::Status status = dbh->Delete(rocksdb::WriteOptions(), key_slice);
    
    return status.ok();
}

extern "C" bool close(void *db)
{
    rocksdb::DB* dbh = reinterpret_cast<rocksdb::DB*>(db);
    
    delete dbh;
}

