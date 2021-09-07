#pragma once
#define HASH_TABLE_SIZE 10000
#include"utilities.h"


namespace hash_map{
    class hash_table{
    public:
        char* key;
        char* value;
        hash_table* next;
};



u_int hash(string key);
hash_table** init();
void print(hash_map::hash_table** hashtable);


}
