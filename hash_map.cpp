#include "hash_map.h"
#include <cstring>

/*
table =         0x5653f8c0  8eb0    ------->    94918655643312    
table->arr =    0x5653f8c0  92e0	------->    94918655644384 
diferent = 1072


table =         0x55884d3f  1eb0	------->    94043899895472 
table->arr =    0x55884d3f  22e0    ------->    94043899896544
diferent = 1072



HASH_TABLE_SIZE = 10
table =         0x5590fad3  7eb0        ------->    94081171816112
table->arr =    0x5590fad3  82e0        ------->    94081171817184    
diferent = 1072    



table = 0x55dfc71efeb0	
size of table = 8 byte
table->arr = 0x55dfc71f02e0	

size of table->arr = 8 byte

table->arr[0] : 0 Adress is 0x55dfc71f02e0
table->arr[1] : 0 Adress is 0x55dfc71f02e8
table->arr[2] : 0 Adress is 0x55dfc71f02f0
table->arr[3] : 0 Adress is 0x55dfc71f02f8
table->arr[4] : 0 Adress is 0x55dfc71f0300
table->arr[5] : 0 Adress is 0x55dfc71f0308
table->arr[6] : 0 Adress is 0x55dfc71f0310
table->arr[7] : 0 Adress is 0x55dfc71f0318
table->arr[8] : 0 Adress is 0x55dfc71f0320
table->arr[9] : 0 Adress is 0x55dfc71f0328


The size of table->arr as a hole = 80
0	---------->	0xa0xa Adress is 0x55dfc71f02e0
1	---------->	0xa0xa Adress is 0x55dfc71f02e8
2	---------->	0xa0xa Adress is 0x55dfc71f02f0
3	---------->	0xa0xa Adress is 0x55dfc71f02f8
4	---------->	0xa0xa Adress is 0x55dfc71f0300
5	---------->	0xa0xa Adress is 0x55dfc71f0308
6	---------->	0xa0xa Adress is 0x55dfc71f0310
7	---------->	0xa0xa Adress is 0x55dfc71f0318
8	---------->	0xa0xa Adress is 0x55dfc71f0320
9	---------->	0xa0xa Adress is 0x55dfc71f0328

*/
    HashTable* init(){
        //store a pointer to a lonked list
        //An Idetifier of the HashTable
        HashTable* table = new HashTable();

        //Allocate space for every Entries
        //This is going to stroe the head of HASH_TABLE_SIZE number of pointer to a linked lists
        // This is a linked list implementation HERE!! VERY comfusing
        table->head_refs = new pair*[HASH_TABLE_SIZE];

        //Inisialize an Empty Hash map
        for (int i = 0; i < HASH_TABLE_SIZE; i++){
            //Initialize an Empty list in every elelemt of the HASH_TABLE_SIZE
            table->head_refs[i] = NULL;
        }

        return table;
    }

    int hash(const char* key){

        //Initializing the index as 0
        int index_value = 0;

        //go at every letter till the last character in the key
        int key_len = strlen(key);
        for (int i = 0; i < key_len; i++)
                //generete an assosiated ranom number for the key
            index_value = index_value * 37 + key[i];


            //make the key bounded between 0 and HASH_TABLE_SIZE
        index_value = index_value % HASH_TABLE_SIZE;

            //Get the index back
        return index_value;
    }


    pair* make_node(const char* key, const char* value){

            //Allocate space for the linked list NODE
        pair* new_node = new pair[1];
        new_node->key = new char[strlen(key) + 1];      //Add 1 for "\0"
        new_node->value = new char[strlen(value) + 1];  //Add 1 for "\0"
            
            //copy the key and the value in place 
            //If we work with number we can just assigne them like we did in the linked list
        strcpy(new_node->key, key);
        strcpy(new_node->value, value);


        //The pointer to the next node in a linked list be null 
        // Just as we are making a linked list in this step (see the function make NODE !!!!)
        new_node->next = NULL;

    return new_node;
    }







    void insert_pair(HashTable* table, const char* key, const char* value){
        
        int slot = hash(key);

        //look up for an Entry set
        pair* head_ref = table->head_refs[slot];

        //no entry (NULL) that mean that the slot in Empty , we are going to inserte imediatly
        if (head_ref == NULL)
        {
            table->head_refs[slot] = make_node(key,value);
            return;
        }

        pair* prev;
            //Go throw the list in the given slot intil reach the end or find the same key
            //if the second accure we are going to change the value simply
        while (head_ref != NULL)
        {
            if(strcmp(head_ref->key, key) == 0){
                delete head_ref->value;
                head_ref->value = new char[strlen(value) + 1];
                strcpy(head_ref->value, value);
                return;
            }

            //Go to the next element in the list The same as the linked list
            prev = head_ref;
            head_ref = head_ref->next;
        }
        
        // In this place we reached without a match ,add new element in the linked list 
        // The same as append method of a linked list
        prev->next = make_node(key, value);

    }




void print_hash_table(HashTable* table){

    for (int i = 0; i < HASH_TABLE_SIZE; i++){
        pair* head_ref = table->head_refs[i];

        if(head_ref == NULL)
            continue;
        
        std::cout<<"place["<< i <<"] : ";
        //Going throw every and each element in the given slot and print every node in the linked list 
        while (head_ref != NULL){
            std::cout<<head_ref->key <<" = "<<head_ref->value;
            head_ref = head_ref->next;
        }
        std::cout<<"\n";
    }
}


