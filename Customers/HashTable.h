// ---------------------------------------------------- HashTable.h -----------------------------------------------------
// Kyle Lai CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/6/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - HashTable class is used to store Customer objects in a hash table and implements open hashing using a vector of nodes
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include <string>
#include <set>
#include <fstream>

static const int MAX_DEFAULT_SIZE = 100;

using namespace std;

template <class T>
class HashTable
{
    friend ostream &operator<<(ostream &ostream, const HashTable<T> &rhs)
    {
        for (int i = 1; i < rhs.tableSize; i++)
        {

            if (rhs.Table[i])
            {

                ostream << "[" << i << "] [" << *rhs.Table[i]->nodeData->data << "]" << endl;
            }
        }
        return ostream;
    }

public:
    HashTable();
    ~HashTable();
    virtual int getHashIndex(T *key) const;
    bool insert(T *newItem);
    bool remove(T *newItem);
    void clear();
    bool contains(T *searchKey) const;
    T *get(T *searchKey) const;
    int getNumberOfItems() const;
    bool isEmpty() const;
    int size() const;
    // assignment operator

protected:
    struct Node
    {
        T *data;
        Node *next;
        int key;
    };

    struct HashTableNode
    {
        int bCount;
        Node *nodeData;
    };

    HashTableNode **Table;
    int count;
    int tableSize;
};
#endif