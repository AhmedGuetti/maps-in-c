#include"linked-list.h"
#include"utilities.h"
#include<iostream>


//Initialize the linked list

Node** list_init(){
    // Aloccate for the header of the list in the Heap 
    Node** head = new Node*();

    // Initialize an Empty List
    *head = NULL;

    // Make the pointer of the list accessible EVERYWHERE 
    // Do NOde** to avoid Globale varible
    return head;

}

Node* creat_node(int data){
    // Alloccate spave for the new Node
    Node* new_node = new Node();

    // Initialize the default value of a new node
    new_node->data = data;
    new_node->next = NULL;

    // Make the node accessible using it's address
    return new_node;
}

void push(Node** head_ref, int data){

    // Make a node in the memory and give the default property
    Node* new_node = creat_node(data);

    // Make the new_node point to the first element (become the second)
    new_node->next = (*head_ref)->next;

    // Reinitialize the head_ref
    (*head_ref)->next = new_node;

}

void print_list(Node** head_ref){


    // Loop all the way to the last element of the list
    while ((*head_ref)->next != NULL)
    {
        //print the data value and format a little bit
       Log<int>((*head_ref)->data);
       Log<const char*>(", ");

    }
    Log<const char*>("\n");

}
