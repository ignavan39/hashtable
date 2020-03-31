//
// Created by necrobuther on 31.03.2020.
//

#include <sstream>
#include "HashTable.h"
template<typename Key, typename Value>
HashTable<Key, Value>::HashTable():_size{0},capacity{11},store() {}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t _capacity):_size{0},capacity{_capacity},store() {}

template<typename Key, typename Value>
int HashTable<Key, Value>::hash(const string& hasher) {
    int idx = 0;
    for(char i : hasher){
        idx += static_cast<int> (i)*(i+1);
    }
    return idx % capacity;
}

template<typename Key, typename Value>
string HashTable<Key, Value>::convert_to_string(K key)  {
   ostringstream os;
   os<<key;
   return os.str();
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::load_factor() const {
    return capacity;
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::size() const {
    return _size;
}



template<typename Key, typename Value>
void HashTable<Key, Value>::insert(pair<K, V> pair1) {
     insert(pair1.first,pair1.second);
}

template<typename Key, typename Value>
void HashTable<Key, Value>::insert(K key, V value){
    int index_ = hash(convert_to_string(key));
    for(auto item = store.begin();item!=store.end();item++){
        if(item->first == index_){
            auto& buff_list = item->second;
        }
    }
}






