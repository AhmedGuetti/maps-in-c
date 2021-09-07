#ifndef _HM_MAP_
#define _HM_MAP_

#ifdef _MSC_VER
#pragma once
#endif

#include "utilities.h"

#define OMAP_API static

struct OMap;
struct OMap_Iterator;
struct OMap_Node;

typedef struct OMap_Entry
{
	union
	{
		OM_int8_t	i8val;
		OM_int16_t	i16val;
		OM_int32_t	i32val;
		OM_float_t	fval;
		OM_double_t	dval;
		OM_cstring_t sval;
		OM_data_t	val;
	};
	size_t size;
	enum OM_DataType type;
} OMap_Key, OMap_Value;


struct OMap_Iterator
{
	struct OMap_Node* Current;
};


typedef bool(*CmpPred)(const OMap_Key* a, const OMap_Key* b);


struct OMap* omap_alloc(OM_DataType key_type, CmpPred cmp_func);

bool omap_insert(struct OMap* map, const OMap_Key key, const OMap_Value val);

void omap_erase(struct OMap* map, const OMap_Key key);

void omap_clear_all(struct OMap* map);

bool omap_contains(struct OMap* map, const OMap_Key key);


struct OMap_Iterator omap_iterator_first(struct OMap* map);

const OMap_Key* omap_iterator_key(struct OMap_Iterator* iterator);

OMap_Value* omap_iterator_value(struct OMap_Iterator* iterator);

bool omap_iterator_next(struct OMap_Iterator* iterator);


void omap_release(struct OMap* map);



#endif