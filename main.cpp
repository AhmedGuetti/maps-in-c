#include<iostream>
#include"utilities.h"
#include"map.h"
#include"linked-list.h"




int main(int argc, char **argv){
    list::Node** head_ref = list::init();
    list::push(head_ref, 10);
    list::push(head_ref, 20);
    list::push(head_ref, 30);
    list::push(head_ref, 40);
    list::push(head_ref, 50);
    list::push(head_ref, 60);
    list::push(head_ref, 70);
    list::push(head_ref, 80);
    list::push(head_ref, 90);
    list::push(head_ref, 100);
    list::print(head_ref);
    list::append(head_ref, 0);
    list::append(head_ref, 1);
    list::append(head_ref, 2);
    list::append(head_ref, 3);
    list::append(head_ref, 4);
    list::append(head_ref, 5);
    list::append(head_ref, 6);
    list::append(head_ref, 7);
    list::append(head_ref, 9);
    list::append(head_ref, 10);
    list::print(head_ref);
    Log<int>(list::size(head_ref));



    std::cin.get();
    return 0;
}