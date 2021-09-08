#ifndef _OM_STRING_
#define _OM_STRING_

#ifdef _MSC_VER
#pragma once
#endif

#include "utilities.h"


#define OM_STR_API static

struct OM_string
{
	char* str_ptr;
	OM_size_t size;
};


OM_STR_API struct OM_string OM_string_cpy(struct OM_string* const to, const struct OM_string* const from)
{
	strncpy_s(to->str_ptr, to->size, from->str_ptr, from->size);
}

OM_STR_API struct OM_string OM_new_string_ex(const struct OM_string* const other)
{
	struct OM_string data = { 0 };
	if (other->size)
	{
		data.str_ptr = malloc(other->size);
		data.size = other->size;
		OM_string_cpy(&data, other);
	}
	return data;
}

OM_STR_API struct OM_string OM_new_string(const char* str)
{
	struct OM_string data = { 0 }, out = { 0 };
	data.size = str ? (strlen(str) + 1) : 0;
	data.str_ptr = (char*)(str);
	return OM_new_string_ex(&data);
}


OM_STR_API void OM_delete_string(struct OM_string* str)
{
	free(str->str_ptr);
	str->size = 0;
}

int OM_format(char* buffer, size_t len, char* fmt, ...);

#endif