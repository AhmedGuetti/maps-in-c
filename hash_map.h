#pragma once
#define HASH_TABLE_SIZE 100
#include"utilities.h"


    class pair{
        public:
        int key;
        const char* value;

        pair(int key, const char* value){
            this->key = key;
            this->value = value;
        }
    };

    class HashTable{
        public:
        //The data we are storing are key_value pair
        pair value;

        // store the next element of the linked list in collisian caases
        HashTable* next;

        //store the HashTable
        pair** arr;
    };



pair** init();

unsigned int hash(int key);

void InsertNode(pair** arr, int key, const char* value);

void print_hash_map(pair** arr);
