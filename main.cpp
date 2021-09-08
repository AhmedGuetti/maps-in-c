#include<iostream>
#include"utilities.h"
#include"hash_map.h"
#include"linked-list.h"




int main(int argc, char **argv){

    HashTable* table1 = init();

    insert_pair(table1, "Mohammed", "1970");
    insert_pair(table1, "Meryem", "1976");
    insert_pair(table1, "Ahmed", "2002");
    insert_pair(table1, "Ouiam", "2004");
    insert_pair(table1, "ziyad", "2008");
    insert_pair(table1, "Arwa", "2017");

    print_hash_table(table1);





    std::cin.get();
    return 0;
}