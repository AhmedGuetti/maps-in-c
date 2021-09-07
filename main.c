#include <stdio.h>

#include "utilities.h"
#include "map.h"


bool Cmp_Less(const OMap_Key* a, const OMap_Key* b)
{
    printf("Incoming: %i, Current: %i\n", a->i32val, b->i32val);
    return a->i32val < b->i32val;
}

int main(){

    while (true)
    {
        {
            char str[10];
            gets_s(str, sizeof(str));
        }
        
        struct OMap* map = omap_alloc(OM_INT32, &Cmp_Less);


        /*
        for (int i = 0; i < 10; i++)
        {
            OMap_Key k = { i, sizeof(int), OM_INT32 };
            omap_insert(map, k, k);
        }
        */
        for (int i = 10; i > 1; i--)
        {
            OMap_Key k = { i, sizeof(int), OM_INT32 };
            omap_insert(map, k, k);
        }

        {
            for (struct OMap_Iterator cur = omap_iterator_first(map); cur.Current != 0; omap_iterator_next(&cur))
            {
                printf("%i = %i\n", omap_iterator_key(&cur)->i32val, omap_iterator_value(&cur)->i32val);
            }
        }
    }
    return 0;
}