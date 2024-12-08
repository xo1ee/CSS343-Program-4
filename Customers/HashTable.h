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
#include <vector>
#include <string>
#include <functional>

template <typename K, typename V>
class HashTable {
public:
    HashTable(int size = DEFAULT_TABLE_SIZE);
    ~HashTable();

    bool insert(const K& key, const V& value);
    bool remove(const K& key);
    V* search(const K& key) const;
    void clear();
    void print() const;

private:
    static const int DEFAULT_TABLE_SIZE = 991; // selected large prime number
    struct TableNode {
        K key;
        V value;
        TableNode* next;

        TableNode(const K& key, const V& value, TableNode* next = nullptr)
            : key(key), value(value), next(next) {}
    };

    std::vector<TableNode*> table;
    int tableSize;

    int hash(const K& key) const;
    void clearNodeList(TableNode* node);
};
#endif