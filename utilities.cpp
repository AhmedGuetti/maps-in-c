#include"utilities.h"


u_int strlen(string text){
    u_int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    return i;
}