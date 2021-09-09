#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"






Node* make_node(int key, int value){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
}

    int hash(int key){
    return key % HASH_MAP_SIZE;
    }



Node*** make_table(){
    Node*** table = (Node***)malloc(sizeof(Node**) * HASH_MAP_SIZE);
    for (int i = 0; i < HASH_MAP_SIZE; i++){
        table[i] = (Node**) malloc(sizeof(Node*));
        *table[i] = NULL;
    }
    return table;
}


void insert_node(Node*** table, int key, int value){
        
        int slot = hash(key);

        //look up for an Entry set
        Node* curr = *table[slot];

        Node* new_node = make_node(key, value);
        //no entry (NULL) that mean that the slot in Empty , we are going to inserte imediatly
        if (*table[slot] == NULL)
        {
            *table[slot] = new_node;
            return;
        }

            //Go throw the list in the given slot intil reach the end or find the same key
            //if the second accure we are going to change the value simply
        while (curr->next != NULL) 
        {
            //Go to the next element in the list The same as the linked list
            curr = curr->next;
        } 
        
        
        // In this place we reached without a match ,add new element in the linked list 
        // The same as append method of a linked list
        if(curr->key == key)
            curr->value = value;   
        else
            curr->next = new_node;
    }


    void delete_node(Node*** table , int key){
        int slot = hash(key);
        Node* curr = *table[slot];
    //No slut mean no node
    if (curr == NULL)
        return;
    Node* prev;
    int idx = 0;

    while (curr != NULL)
    {
        if (curr->key == key){
            //The first node and no next node
            if (curr->next == NULL && idx == 0)
                *table[slot] = NULL;
            
            //The Middle element
            if (curr->next == NULL && idx != 0)
                prev->next = curr->next;
            
            // first node with a next node
            if (curr->next != NULL && idx == 0)
                *table[slot] = curr->next;
            
            
            // last node
            if (curr->next == NULL && idx != 0)
                prev->next = NULL;
            

            //Free the space of the node 
            free(curr);
            return;
        }

        free(curr);

        prev = curr;
        curr = curr->next;
        idx ++;
    }
    }


int get_node(Node*** table, int key){
    int slot = hash(key);
    Node* curr = *table[slot];

    if (curr == NULL)
    {
        return -1;
    }
    

    while (curr != NULL)
    {
            if (curr->key == key)
                return curr->value;
            


        curr = curr->next;
    }
    return -1;
}

void display(Node*** table){

    for (int i = 0; i < HASH_MAP_SIZE; i++)
    {
    Node** head_ref = table[i];
    Node* curr = *head_ref;

    printf("palce[%d] :\t", i);
    while (curr!=NULL)
    {
        printf("%d = %d\t",curr->key, curr->value);
        curr = curr->next;
    }
        printf("\n");    
    }
    

}




