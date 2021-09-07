#pragma once
#include<iostream>
//Simple output Function using the stanrdart I/O of CPP

/*
 * Datatypes
 */
typedef unsigned int            u_int;
typedef const int               c_int;
typedef const unsigned int      c_u_int;
typedef long long               ll;
typedef const char              c_char;
typedef const char*             string;
typedef long int                l_int;          // 16bits
typedef const long int          c_l_int;        // 16bits
typedef unsigned long int       u_l_int;        // 16bits
typedef const unsigned long int c_u_l_int;      // 16bits



template <typename T>
void Log(T message){std::cout << message;}



u_int strlen(string text);