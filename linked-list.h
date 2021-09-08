#pragma once


namespace list
{
    class Node{
    public:
        int data;
        Node* next;
};



Node** init();
void push(Node** head_ref, int data);
void append(Node** head_ref, int data);
void inserte(Node** head_ref, int pos,int data);
int size(Node** head_ref);
void print(Node** head_ref);
Node* creat_node(int data);

}
