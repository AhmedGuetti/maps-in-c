#include "hash_map.h"
#include "utilities.h"




    pair** init(){
        //Allocate space for the table
        pair** arr = new pair*[HASH_TABLE_SIZE];

        //Inisialize an Empty Hash map
        for (int i = 0; i < HASH_TABLE_SIZE; i++){
            arr[i] = NULL;
        }

        return arr;

    }

    unsigned int hash(int key){
        return key % HASH_TABLE_SIZE;
    }


    void InsertNode(pair** arr, int key, const char* value){
        pair* temp = new pair(key, value);

        int index = hash(key);

        while (arr[index] != NULL && arr[index]->key != key )
        {
           index++;
           index = index % HASH_TABLE_SIZE;
        }
        arr[index] = temp;
        
    }


void print_hash_map(pair** arr){

    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        std::cout<<i<<"\t---------->\t"<<arr[i]<<"\n";


    }
}
