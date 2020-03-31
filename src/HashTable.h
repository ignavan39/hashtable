//
// Created by necrobuther on 31.03.2020.
//

#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H

#include <cstdio>
#include <list>
#include <string>

using namespace std;
template <typename Key,typename Value>
class HashTable {
public:

    using K = Key;
    using V = Value;

    bool insert(K &key, V &value) const;
    bool contain(K &key) const;
    V at(K &key);
    void makeEmpty();
    bool empty() const;
    size_t size() const;
    size_t load_factor() const;
    /*class TableIterator{
        TableIterator(HashTable<K,V>);

    };*/
    HashTable();
    explicit HashTable(size_t capacity);
    HashTable(HashTable<K,V>&);
    HashTable(HashTable<K,V>&&) noexcept ;

private:
    size_t capacity;
    size_t _size;
    list<pair<int,list<pair<K,V>>>> store;
    int hash(const string& hasher);
    string convert_to_string(K key) const;
};




#endif //TASK4_HASHTABLE_H
