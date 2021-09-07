#include"linked-list.h"
#include"utilities.h"
#include<iostream>


// Use namespace to separate the name of the function from other datatime
namespace list
{

//Initialize the linked list

Node** init(){
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
    new_node->next = (*head_ref);

    // Reinitialize the head_ref
    (*head_ref) = new_node;

}

void append(Node** head_ref, int data){

    // Make a node in the memory and give the default property
    Node* new_node = creat_node(data);

    // Empty list case
    if((*head_ref == NULL)){
        (*head_ref) = new_node;
        return;
    }

    // Make a copy of the first element 
    Node* last = *head_ref;

    // travest ill the last node
    while (last->next != NULL)
    {
       last = last->next;
    }
    
    // change the next to new nodee address
    last->next = new_node;
    return;
    

}
void inserte(Node** head_ref, int pos,int data){
    // Make a node in the memory and give the default property
    Node* new_node = creat_node(data);


    // Handle negative and indertion in a 0 position 
    if (pos < 0 ){
        Log<const char*>("ERROR : position Should not be negative Only positive integer are valid \n");
        return;
        // In the case of an Empty list or a inserte at the firat postision 0
    }else if(pos == 0 || *head_ref == NULL){
        push(head_ref, data);
        return;
    }
    
    // a copy of the first head element
    Node* curr = *head_ref;

    // Traverse till the element befor the position (=pos)
    for (int i = 1; i < pos; i++)
    {
       curr = curr->next;

        // Handle the case of pos > size of the list
        // Just add the elelemt in the end
       if(curr->next == NULL){
           append(head_ref, data);
           return;
       }
    }

    // Just think about it for a moment!
    new_node->next = curr->next;
    curr->next = new_node;
}

void pop(Node** head_ref){
    // Save the first elelemt address to not lose it in the process
    Node* temp = *head_ref;

    // Reinitialize the head
    *head_ref = (*head_ref)->next;

    // free the address of the first old node
    delete temp;
}


void pop_back(Node** head_ref){

    Node* last = (*head_ref)->next;
    Node* lastprev = *head_ref;

    while (last->next != NULL)
    {
        lastprev = lastprev->next;
        last = last->next;
    }
    


}






int size(Node** head_ref){
    // make a copy of the head element
    Node* curr = *head_ref;

    //initialize the size of 1 because we wxclude the 0 witch mean no elelment
    int size = 1;

    //Hnadle the Emty list case
    if(curr == NULL){return 0;}

    //travese the list till the end
    while (curr->next != NULL)
    {
        curr = curr->next;
        size ++;
    }

    //get the size in the end
    return size;

}




void print(Node** head_ref){

    Node* curr = *head_ref;
    // Loop all the way to the last element of the list
    while (curr->next != NULL)
    {

                // Add some color to linux Terminale Delete this line if Youare in window
        Log<const char*>("\033[47;30m");
                //print the data value and format a little bit
        Log<int>(curr->data);
        Log<const char*>(", ");
       curr= curr->next;

    }
    Log<const char*>("\n");

}






}
