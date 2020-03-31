//
// Created by necrobuther on 31.03.2020.
//

#include <sstream>
#include "HashTable.h"
template<typename Key, typename Value>
HashTable<Key, Value>::HashTable():_size{0},capacity{11},store() {}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t capacity):_size{0},capacity{capacity},store() {}

template<typename Key, typename Value>
int HashTable<Key, Value>::hash(const string& hasher) {
    int idx = 0;
    for(char i : hasher){
        idx += static_cast<int> (i)*(i+1);
    }
    return idx % capacity;
}

template<typename Key, typename Value>
string HashTable<Key, Value>::convert_to_string(K key) const {
   ostringstream os;
   os<<key;
   return os.str();
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::load_factor() const {
    return _size;
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::size() const {
    return capacity;
}
