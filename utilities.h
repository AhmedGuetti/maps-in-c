#ifndef _OM_UTILITIES_
#define _OM_UTILITIES_

#ifdef _MSC_VER
#pragma once
#endif

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>


typedef char OM_int8_t;
typedef unsigned char OM_uint8_t;

typedef short OM_int16_t;
typedef unsigned short OM_uint16_t;

typedef int	OM_int32_t;
typedef unsigned int OM_uint32_t;
typedef OM_uint32_t OM_size_t;

typedef long long OM_int64_t;
typedef unsigned long long OM_uint64_t;

typedef float OM_float_t;
typedef double OM_double_t;


typedef const char* OM_cstring_t;
typedef void* OM_data_t;

<<<<<<< HEAD
typedef enum OM_DataType
{
	OM_INT8,
	OM_INT16,
	OM_INT32,
	OM_FLOAT,
	OM_DOUBLE,
	OM_STRING,
	OM_PTR,
} OM_DataType;
=======
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
>>>>>>> 0f252618036beb13f0e0be1500080a052ec9f154

#endif