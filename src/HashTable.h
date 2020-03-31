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
    /*class TableIterator{
        TableIterator(HashTable<K,V>);

    };*/
    HashTable();
    HashTable(size_t capacity);
    HashTable(HashTable<K,V>&);
    HashTable(HashTable<K,V>&&);

private:
    size_t count;
    size_t _size;
    list<pair<string,list<V>>> store;
    string hash(K key);
};


#endif //TASK4_HASHTABLE_H
