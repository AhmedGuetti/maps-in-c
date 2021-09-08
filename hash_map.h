#ifndef _HASH_MAP_H
#define _HASH_MAP_H



#define HASH_TABLE_SIZE 10000



    typedef struct {
        char* key;
        char* value;
        struct pair* next;

    }pair;

    typedef struct {
        //store the HashTable
        pair** head_refs;
    } HashTable;



    HashTable* init(); 

    int hash(const char* key);

    pair* make_node(const char* key, const char* value);

    void insert_pair(HashTable* table, const char* key, const char* value);

    void print_hash_table(HashTable* table);

#endif