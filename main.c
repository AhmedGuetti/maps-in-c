#include <stdio.h>
#include"hash_map.h"
#include"utilities.h"
//#include"map.h"



// bool Cmp_Less(const OMap_Key* a, const OMap_Key* b)
// {
// //    printf("Incoming: %i, Current: %i\n", a->value.i32val, b->value.i32val);
//     return a->value.i32val < b->value.i32val;
// }


int main(){

    // while (true)
    // {
    //     struct OMap* map = omap_alloc(OM_INT32, &Cmp_Less);

        
    //     for (int i = -1; i < 6; i++)
    //     {
    //         OMap_Key k = { .value.i32val = i, sizeof(int), OM_INT32 };
    //         omap_insert(map, k, k);
    //     }
        
    //     for (int i = 10; i > 4; i--)
    //     {
    //         OMap_Key k = { .value.i32val = i, sizeof(int), OM_INT32 };
    //         OMap_Key v = { .value.i32val = i+10, sizeof(int), OM_INT32 };
    //         omap_insert(map, k, v);
    //     }

    //     for (int i = 9; i < 12; i++)
    //     {
    //         OMap_Key k = { .value.i32val = i, sizeof(int), OM_INT32 };
    //         printf("Contains %i ? %i\n", k.value.i32val, omap_contains(map, k));
    //     }

    //     printf("Size: %i\n", omap_size(map));

    //     {
    //         OMap_Key k = { .value.i32val = 10, sizeof(int), OM_INT32 };
    //         omap_erase(map, k);
    //     }

    //     printf("Size: %i\n", omap_size(map));

    //     for (int i = 9; i < 12; i++)
    //     {
    //         OMap_Key k = { .value.i32val = i, sizeof(int), OM_INT32 };
    //         printf("Contains %i ? %i\n", k.value.i32val, omap_contains(map, k));
    //     }

    //     {
    //         for (struct OMap_Iterator cur = omap_iterator_first(map); cur.Current != 0; omap_iterator_next(&cur))
    //         {
    //             printf("%i = %i\n", omap_iterator_key(&cur)->value.i32val, omap_iterator_value(&cur)->value.i32val);
    //         }
    //     }

    //     {
    //         omap_clear_all(map);
    //         for (struct OMap_Iterator cur = omap_iterator_first(map); cur.Current != 0; omap_iterator_next(&cur))
    //         {
    //             printf("%i = %i\n", omap_iterator_key(&cur)->value.i32val, omap_iterator_value(&cur)->value.i32val);
    //         }
    //     }

    //     omap_release(map);

    //     {
    //         char str[10];
    //         gets_s(str, sizeof(str));
    //     }

    // }



    // Ahmed Guetti Hash map implementation of a hash map 

    HashTable* table1 = init();

    insert_pair(table1, "Mohammed", "1970");
    insert_pair(table1, "Meryem", "1976");
    insert_pair(table1, "Ahmed", "2002");
    insert_pair(table1, "Ouiam", "2004");
    insert_pair(table1, "ziyad", "2008");
    insert_pair(table1, "Arwa", "2017");

    print_hash_table(table1);

    
    //End of the My space
    return 0;
}