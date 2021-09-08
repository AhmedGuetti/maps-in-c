#ifndef _OM_MAP_
#define _OM_MAP_

#ifdef _MSC_VER
#pragma once
#endif

#include "utilities.h"

#define OMAP_API static

struct OMap;
struct OMap_Iterator;
struct OMap_Node;


union OMap_Value
{
	bool		bval,	barr[8],*	bptr;
	OM_int8_t	i8val,	i8arr[8],*	i8ptr;
	OM_int16_t	i16val, i16arr[4],* i16ptr;
	OM_int32_t	i32val, i32arr[2],* i32ptr;
	OM_int64_t	i64al,* i64ptr;

	OM_uint8_t	u8val,	u8arr[8],*	u8ptr;
	OM_uint16_t	u16val, u16arr[4],* u16ptr;
	OM_uint32_t	u32val, u32arr[2],* u32ptr;
	OM_uint64_t	u64al,* u64ptr;

	OM_float_t	fval, farr[2],* fptr;
	OM_double_t	dval,* dptr;

	OM_cstring_t cstr;
	OM_data_t	ptr;
};

typedef struct OMap_Entry
{
	union OMap_Value value;
	size_t size;
	enum OM_DataType type;
} OMap_Key, OMap_Value;


struct OMap_Iterator
{
	struct OMap_Node* Current;
};


typedef bool(*CmpPred)(const OMap_Key* a, const OMap_Key* b);


/// <summary>
/// Initialize an ordered map with predefined types and compare function
/// </summary>
struct OMap* omap_alloc(OM_DataType key_type, CmpPred cmp_func);

/// <summary>
/// Insert or overwrite a [Key, value] to the map
/// </summary>
/// <param name="overwrite">if true and the key already exists, value will be rewritten, else it will insert the value next to it if 'fail' is false</param>
/// <param name="fail">if true and the key already exists, function will return false, can't be combined with 'overwrite'</param>
bool omap_insert_ex(struct OMap* map, const OMap_Key key, const OMap_Value val, bool overwrite, bool fail);

#define omap_insert(map, key, val) omap_insert_ex(map, key, val, false, true)

#define omap_insert_or_overwrite(map, key, val) omap_insert_ex(map, key, val, true, false)

#define omap_insert_dup(map, key, val) omap_insert_ex(map, key, val, false, false)

/// <summary>
/// Merge othermap into map, and release it
/// </summary>
/// <param name="map"></param>
/// <param name="othermap"></param>
/// <param name="overwrite"></param>
/// <returns></returns>
bool omap_merge(struct OMap* map, struct OMap* othermap, bool overwrite);

/// <summary>
/// Erase a [key, value] from the map
/// </summary>
bool omap_erase(struct OMap* map, const OMap_Key key);

/// <summary>
/// Erase all of the [key, value]s in the map
/// </summary>
/// <param name="map"></param>
void omap_clear_all(struct OMap* map);

/// <summary>
/// Tests whether the map contains the key
/// </summary>
bool omap_contains(struct OMap* map, const OMap_Key key);

/// <summary>
/// Get the size of the [key, value]s in the map
/// </summary>
size_t omap_size(struct OMap* map);

/// <summary>
/// Test if map's size is zero
/// </summary>
OMAP_API bool omap_empty(struct OMap* map)
{
	return omap_size(map) == 0;
}


/// <summary>
/// Return and iterator to the first [key, value] of the map
/// </summary>
struct OMap_Iterator omap_iterator_first(struct OMap* map);


/// <summary>
/// Test whether or not the iterator is valid
/// </summary>
#define omap_iterator_bad(iterator) (iterator.Current == NULL)

/// <summary>
/// Get the [key] of the current iterator
/// </summary>
const OMap_Key* omap_iterator_key(struct OMap_Iterator* iterator);

/// <summary>
/// Get the [value] of the current iterator
/// </summary>
OMap_Value* omap_iterator_value(struct OMap_Iterator* iterator);

/// <summary>
/// Get the next iterator
/// </summary>
bool omap_iterator_next(struct OMap_Iterator* iterator);


/// <summary>
/// Delete the map and release all of it's [key, value]s
/// </summary>
/// <param name="map"></param>
void omap_release(struct OMap* map);



#endif