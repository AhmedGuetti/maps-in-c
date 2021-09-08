#pragma once
#define HASH_TABLE_SIZE 10
#include"utilities.h"


    class pair{
        public:
        char* key;
        char* value;
        pair* next;

    };

    class HashTable{
        public:
        //store the HashTable
        pair** head_refs;
    };



    HashTable* init();
    
    int hash(const char* key);

    pair* make_node(const char* key, const char* value);

    void insert_pair(HashTable* table, const char* key, const char* value);

    void print_hash_table(HashTable* table);

