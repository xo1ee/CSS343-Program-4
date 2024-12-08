// ---------------------------------------------------- HashTable.cpp -----------------------------------------------------
// Kyle Lai CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/6/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - implements the functions used by HashTable class. Used to store data in a hash table
// --------------------------------------------------------------------------------------------------------------------

#include "HashTable.h"
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename K, typename V>
HashTable<K, V>::HashTable(int size) : tableSize(size) {
    table.resize(size, nullptr);
}

template <typename K, typename V>
HashTable<K, V>::~HashTable() {
    clear();
}

template <typename K, typename V>
bool HashTable<K, V>::insert(const K& key, const V& value) {
    int index = hash(key);
    TableNode* newNode = new TableNode(key, value);

    if (!table[index]) {
        table[index] = newNode;
    } else {
        TableNode* current = table[index];
        while (current->next) {
            if (current->key == key) {
                delete newNode; // Prevent memory leak
                return false;  // Key already exists
            }
            current = current->next;
        }
        current->next = newNode;
    }
    return true;
}

template <typename K, typename V>
bool HashTable<K, V>::remove(const K& key) {
    int index = hash(key);
    TableNode* current = table[index];
    TableNode* prev = nullptr;

    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;  // Key not found
}

template <typename K, typename V>
V* HashTable<K, V>::search(const K& key) const {
    int index = hash(key);
    TableNode* current = table[index];

    while (current) {
        if (current->key == key) {
            return &current->value;
        }
        current = current->next;
    }
    return nullptr;  // Key not found
}

template <typename K, typename V>
void HashTable<K, V>::clear() {
    for (int i = 0; i < table.size(); ++i) {
        clearNodeList(table[i]);
        table[i] = nullptr;
    }
}

template <typename K, typename V>
void HashTable<K, V>::clearNodeList(TableNode* node) {
    while (node) {
        TableNode* temp = node;
        node = node->next;
        delete temp;
    }
}

template <typename K, typename V>
void HashTable<K, V>::print() const {
    for (int i = 0; i < table.size(); ++i) {
        TableNode* current = table[i];
        std::cout << "[" << i << "]";
        while (current) {
            std::cout << " -> {" << current->key << ": " << current->value << "}";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

template <typename K, typename V>
int HashTable<K, V>::hash(const K& key) const {
    return std::hash<K>()(key) % tableSize;
}