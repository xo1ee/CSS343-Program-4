// ---------------------------------------------------- HashTable.cpp -----------------------------------------------------
// Kyle Lai CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/6/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - implements the functions used by HashTable class. Used to store data in a hash table
// --------------------------------------------------------------------------------------------------------------------
#include "HashTable.h"
#include <iostream>
using namespace std;

template<class T>
HashTable<T>::HashTable()
{
	tableSize = MAX_DEFAULT_SIZE;
	Table = new HashTableNode*[MAX_DEFAULT_SIZE];

	for (int i = 0; i < tableSize; i++)
	{
		Table[i] = NULL;
	}

}
template<class T>
HashTable<T>::~HashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (Table[i])
		{
			delete Table[i]->nodeData->data;
			delete Table[i]->nodeData;
			delete Table[i];
		}

	}

	delete Table;
}

template<class T>
int HashTable<T>::getHashIndex(T* key) const
{
	return key->hash() % tableSize;
}


template<class T>
bool HashTable<T>::insert(T* newItem)
{

	Node* newNode = new Node;
	newNode->data = newItem;
	newNode->next = NULL;


	HashTableNode* newHashNode = new HashTableNode;
	int hashIndex = getHashIndex(newItem);
	newNode->key = hashIndex;

	newHashNode->nodeData = newNode;

	Table[hashIndex] = newHashNode;


	return true;

}

template<class T>
bool HashTable<T>::remove(T* newItem)
{
	return true;
}

template<class T>
void HashTable<T>::clear()
{
}

template<class T>
bool HashTable<T>::contains(T* searchKey) const
{
	int hash = getHashIndex(searchKey);
	
	return Table[hash] != NULL;
}

template<class T>
T * HashTable<T>::get(T * searchKey) const
{

	if (contains(searchKey))
	{
		
		return Table[getHashIndex(searchKey)]->nodeData->data;
	}

	return NULL;
}

template<class T>
int HashTable<T>::getNumberOfItems() const
{
	return 0;
}

template<class T>
bool HashTable<T>::isEmpty() const
{
	return false;
}

template<class T>
int HashTable<T>::size() const
{
	return tableSize;
};