#ifndef _HASH_MAP_H
#define _HASH_MAP_H


#define HASH_MAP_SIZE 10



struct Node {
    int key;
    int value;
    struct Node* next;
};


typedef struct Node Node;



//Function here


Node* make_node(int key, int value);

int hash(int key);

Node*** make_table();

void insert_node(Node*** table, int key, int value);

void delete_node(Node*** table , int key);

int get_node(Node*** table, int key);

void display(Node*** table);







#endif