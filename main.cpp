#include<iostream>
#include"utilities.h"
#include"hash_map.h"
#include"linked-list.h"




int main(int argc, char **argv){

    pair** arr = init();

    InsertNode(arr, 5, "Hello");
       
    print_hash_map(arr);
    std::cin.get();
    return 0;
}