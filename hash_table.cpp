#include"hash_table.h"
#include"utilities.h"
#include <iostream>


namespace hash_map{


    u_int hash(string key){
    u_l_int hash_value = 0;
    u_int key_lenght = strlen(key);

    for (int i = 0; i < key_lenght; i++)
    {
       hash_value = hash_value * (key_lenght - i) + key[i];
    }
    hash_value = hash_value % HASH_TABLE_SIZE;

    return hash_value;
}


    hash_table** init(){
        // Alocate table 
        hash_table** hashtable = new hash_table*;

        //Allocate table entity
        *hashtable = new hash_table[HASH_TABLE_SIZE];

        //Set everything to NULL
        for (int i = 0; i < HASH_TABLE_SIZE; i++){
            hashtable[i] = NULL;
        }

    return hashtable;
    }




void print(hash_map::hash_table** hashtable){
    for (int i = 0; i < HASH_TABLE_SIZE; i++){
            if (hashtable != NULL)
                std::cout << "\t "<< i<< "\t"<<hashtable[i]->value;
            else
                std::cout << "\t "<< i<< "\t -------- ";
            


    }
    

}






}


