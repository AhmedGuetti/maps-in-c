#include "map.h"


typedef struct OMap_Node
{
	struct OMap_Node* NextNode;

	OMap_Key	Key;
	OMap_Value	Value;
} OMap_Node;

struct OMap
{
	OMap_Node* Root;

	OM_DataType KeyType;
	CmpPred CmpPredicate;
	size_t Size;
};


#define OMAP_ALLOC_NODE (OMap_Node*)(calloc(1, sizeof(OMap_Node)))

#define OMAP_FREE_NODE(NODE) free((void*)(NODE))

#define OMAP_NODE_COPY(SRC, KEY, VAL)					\
		memcpy(&(SRC->Key), &KEY, sizeof(OMap_Key));	\
		memcpy(&(SRC->Value), &VAL, sizeof(OMap_Value))


#define OMAP_KEY_EQ(NODE, KEY) (!memcmp(&NODE->Key.value, &KEY.value, KEY.size))


struct OMap* omap_alloc(OM_DataType key_type, CmpPred cmp_func)
{
	struct OMap* map = (struct OMap*)(calloc(1, sizeof(struct OMap)));

	if (map)
	{
		map->KeyType = key_type;
		map->CmpPredicate = cmp_func;
	}

	return map;
}




bool omap_insert_ex(struct OMap* map, const OMap_Key key, const OMap_Value val, bool overwrite, bool fail)
{
	if (!map || map->KeyType != key.type)
		return false;

	if (!map->Root)
	{
		if (map->Root = OMAP_ALLOC_NODE)
		{
			OMAP_NODE_COPY(map->Root, key, val);
			map->Size = 1;
			return true;
		}
		else return false;
	}
	else
	{
		// find the best(smallest, biggest, ..., most compatible) element for insertion, by the predicate function
		OMap_Node* pBack = map->Root,* pFront = pBack->NextNode;

		// only one element in the list, decide if we should back or front insert it
		if (!pFront)
		{
			// insert head or tail
			if (!map->CmpPredicate(&key, &pBack->Key))
			{
				if (pBack->NextNode = OMAP_ALLOC_NODE)
				{
					OMap_Node* pNode = pBack->NextNode;
					OMAP_NODE_COPY(pNode, key, val);
					++map->Size;
					return true;
				}
				else return false;
			}
			else
			{
				OMap_Node* pTmp = pBack;
				if (map->Root = OMAP_ALLOC_NODE)
				{
					OMap_Node* pNode = map->Root;
					OMAP_NODE_COPY(pNode, key, val);
					pNode->NextNode = pBack;
					++map->Size;
					return true;
				}
				else return false;
			}
		}
		else
		{
			while (pFront)
			{
				if (map->CmpPredicate(&key, &pFront->Key))
					break;

				pBack = pFront;
				pFront = pFront->NextNode;
			}

			if ((fail || overwrite) && OMAP_KEY_EQ(pBack, key))
			{
				if (fail)
					return false;
				else if (overwrite)
				{
					memcpy(&pBack->Value, &val, sizeof(OMap_Value));
					return true;
				}
			}

			OMap_Node* pTmp = pBack->NextNode;
			if (pBack->NextNode = OMAP_ALLOC_NODE)
			{
				OMap_Node* pNode = pBack->NextNode;
				OMAP_NODE_COPY(pBack->NextNode, key, val);
				pNode->NextNode = pTmp;
				++map->Size;
				return true;
			}
			else return false;
		}
	}
}

bool omap_merge(struct OMap* map, struct OMap* othermap, bool overwrite)
{
	if (!map || othermap == map || !map)
		return false;

	for (struct OMap_Iterator cur = omap_iterator_first(othermap); cur.Current != 0; omap_iterator_next(&cur))
	{
		if (omap_insert_ex(map, cur.Current->Key, cur.Current->Value, overwrite, false))
			return false;
	}

	omap_release(othermap);
	return true;
}


bool omap_erase(struct OMap* map, const OMap_Key key)
{
	if (!map || map->KeyType != key.type)
		return false;

	OMap_Node* pNode;
	OMap_Node** pBack = &map->Root,* pFront = (*pBack)->NextNode;
	// find by memcmp each key
	while (true)
	{
		if (OMAP_KEY_EQ((*pBack), key))
			goto KeyFound;
		// alternatively we can add 'if (OMAP_KEY_EQ((*pBack), key))' after the end of 'while (pFront)' instead of checking if pFront was NULL
		else if (!pFront)
			break;

		pBack = &(*pBack)->NextNode;
		pFront = (*pBack)->NextNode;
	}
	return false;

KeyFound:

	pNode = *pBack;
	*pBack = pFront;
	free(pNode);
	--map->Size;

	return true;
}


void omap_clear_all(struct OMap* map)
{
	if (!map)
		return;

	OMap_Node* pBack = map->Root;

	while (true)
	{
		OMap_Node* pTmp = pBack;
		pBack = pBack ? pBack->NextNode : NULL;

		if (pTmp)
			free(pTmp);

		if (!pBack)
			break;
	}

	map->Root = NULL;
	map->Size = 0;
}


bool omap_contains(struct OMap * map, const OMap_Key key)
{
	OMap_Node* pBack = map->Root,* pFront = pBack->NextNode;
	while (true)
	{
		if (OMAP_KEY_EQ(pBack, key))
			return true;
		// alternatively we can add 'if (OMAP_KEY_EQ((*pBack), key))' after the end of 'while (pFront)' instead of checking if pFront was NULL
		else if (!pFront)
			break;

		pBack = pBack->NextNode;
		pFront = pBack->NextNode;
	}
	return false;
}

size_t omap_size(struct OMap* map)
{
	return map ? map->Size : 0;
}


struct OMap_Iterator omap_iterator_first(struct OMap* map)
{
	struct OMap_Iterator iter = { map ? map->Root : 0 };
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
	free(map);
}
