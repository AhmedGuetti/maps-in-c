#include "map.h"

typedef struct OMap_Node
{
	struct OMap_Node* NextNode;

	OMap_Key	Key;
	OMap_Value	Value;
} OMap_Node;

struct OMap
{
	OMap_Node* Element;

	OM_DataType KeyType;
	CmpPred CmpPredicate;
};


#define OMAP_ALLOC_NODE (OMap_Node*)(calloc(1, sizeof(OMap_Node)))



OMAP_API bool omap_new_node_internal(struct OMap_Node** cur, const OMap_Key* key, const OMap_Value* val)
{
	if (!*cur)
	{
		*cur = OMAP_ALLOC_NODE;
		if (*cur)
		{
			(*cur)->NextNode = 0;

			memcpy(&(*cur)->Key, key, sizeof(OMap_Key));
			memcpy(&(*cur)->Value, val, sizeof(OMap_Value));
			return true;
		}
		else return false;
	}
	else
	{
		OMap_Node* oldnext = (*cur)->NextNode;
		(*cur)->NextNode = OMAP_ALLOC_NODE;
		if (!(*cur)->NextNode)
		{
			(*cur)->NextNode = oldnext;
			return false;
		}
		else
		{
			(*cur)->NextNode->NextNode = oldnext;

			memcpy(&(*cur)->NextNode->Key, key, sizeof(OMap_Key));
			memcpy(&(*cur)->NextNode->Value, val, sizeof(OMap_Value));
			return true;
		}
	}
}




struct OMap* omap_alloc(OM_DataType key_type, CmpPred cmp_func)
{
	struct OMap* map = (struct OMap*)(calloc(1, sizeof(struct OMap)));

	if (map)
	{
		map->KeyType = key_type;
		map->CmpPredicate = cmp_func;
		map->Element = 0;
	}

	return map;
}


bool omap_insert(struct OMap* map, const OMap_Key key, const OMap_Value val)
{
	if (!map || map->KeyType != key.type)
		return false;


	OMap_Node** pCur = &map->Element;
	if (!*pCur)
	{
		return omap_new_node_internal(pCur, &key, &val);
	}
	else
	{
		struct OMap_Node* pNext = (*pCur)->NextNode;
		while (pNext)
		{
			if (map->CmpPredicate(&key, &(*pCur)->Key))
				break;

			pCur = &(*pCur)->NextNode;
			pNext = (*pCur)->NextNode;
		}

		return omap_new_node_internal(pCur, &key, &val);
	}
}


void omap_erase(struct OMap* map, const OMap_Key key)
{

}


void omap_clear_all(struct OMap* map)
{

}


bool omap_contains(struct OMap * map, const OMap_Key key)
{
	return false;
}


struct OMap_Iterator omap_iterator_first(struct OMap* map)
{
	struct OMap_Iterator iter = { map ? map->Element : 0 };
	return  iter;
}


const OMap_Key* omap_iterator_key(struct OMap_Iterator* iterator)
{
	return !iterator ? 0 : &iterator->Current->Key;
}


OMap_Value* omap_iterator_value(struct OMap_Iterator* iterator)
{
	return !iterator ? 0 : &iterator->Current->Value;
}


bool omap_iterator_next(struct OMap_Iterator* iterator)
{
	iterator->Current = iterator->Current->NextNode;
	return (iterator->Current != 0) ? true : false;
}


void omap_release(struct OMap* map)
{
	omap_clear_all(map);

}
