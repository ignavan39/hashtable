//
// Created by necrobuther on 31.03.2020.
//

#include <sstream>
#include "HashTable.h"
template<typename Key, typename Value>
HashTable<Key, Value>::Table_iterator::Table_iterator(HashTable<Key, Value> other) {
    this->current = other.store.begin();
    this->dive = false;
    this->divingDepth = 0;
}

template<typename Key, typename Value>
typename HashTable<Key,Value>::Table_iterator &HashTable<Key, Value>::
        Table_iterator::operator=(const HashTable::Table_iterator &rhs) {
    this->current = rhs.current;
    this->dive = rhs.dive;
    this->divingDepth = rhs.divingDepth;
    return *this;

}

template<typename Key, typename Value>
typename HashTable<Key,Value>::Table_iterator &HashTable<Key, Value>::Table_iterator::operator++() {
    if(!dive)current++;
    return *this;
}

template<typename Key, typename Value>
const typename HashTable<Key, Value>::Table_iterator  HashTable<Key, Value>::Table_iterator::operator++(int i) {
    current++(i);
    return *this;
}

template<typename Key, typename Value>
Value HashTable<Key, Value>::Table_iterator::operator*() {
    if(current->second.size()>1 && divingDepth < current->second.size()){
        dive = true;
        int i =0;
        auto it = current->second.begin();
        while (i<divingDepth){
            it++;
        }
        divingDepth++;
        return it->second;
    }
    else{
        dive = false;
        divingDepth = 0;
        return current->second.front().second;
    }

}

template<typename Key, typename Value>
bool HashTable<Key, Value>::Table_iterator::operator==(const HashTable::Table_iterator &rhs) const {
    return current == rhs.current && dive == rhs.dive && divingDepth == rhs.divingDepth;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::Table_iterator::operator!=(const HashTable::Table_iterator &rhs) const {
    return !(rhs == *this);
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::Table_iterator &HashTable<Key, Value>::Table_iterator::operator--() {
    return current--;
}

template<typename Key, typename Value>
const typename HashTable<Key, Value> ::Table_iterator HashTable<Key, Value>::Table_iterator::operator--(int i){
    current--(i);
    return *this;
}


template<typename Key, typename Value>
void HashTable<Key, Value>::Table_iterator::setCurrent(typename deque<pair<int,list<pair<Key,Value>>>>::iterator& other) {
    this->current = other;
}


template<typename Key, typename Value>
HashTable<Key, Value>::HashTable():idx_in_prime_array{0},store() {}



template<typename Key, typename Value>
int HashTable<Key, Value>::hash(const string& hasher) {
    int idx = 0;
    for(char i : hasher){
        idx += static_cast<int> (i)*(i+1);
    }
    return idx % array_prime_size_[0];
}

template<typename Key, typename Value>
string HashTable<Key, Value>::convert_to_string(K key)  {
   ostringstream os;
   os<<key;
   return os.str();
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::capacity() const {
    return array_prime_size_[idx_in_prime_array];
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::size() const {
    return store.size();
}



template<typename Key, typename Value>
void HashTable<Key, Value>::insert(pair<K, V> pair1) {
     insert(pair1.first,pair1.second);
}

/**
 *
 * @tparam Key
 * @tparam Value
 * @param key , value
 *
 *
 * if we found a list by this key, then either there is a collision here or
 * we are trying to replace the same element,
 * we need to refer to the internal list that stores the pair (key, value),
 * if the key from the pair matches the input, then this is a case of replacement, if not - conflict
 */

template<typename Key, typename Value>
void HashTable<Key, Value>::insert(K key, V value){
    int index_ = hash(convert_to_string(key));
    bool flag1 = false;
    for(auto item = store.begin();item!=store.end();item++){
        if(item->first == index_){
            flag1 = true;
            //auto& buff_list = item->second;
            bool flag2 = false;
            for(auto buff_LItr = item->second.begin();buff_LItr!=item->second.end();buff_LItr++){
                if(buff_LItr->first == key){
                    if(buff_LItr->second == value)break;
                    else{
                        //item->second.erase(buff_LItr);
                        item->second.emplace(buff_LItr,pair<K,V> (key,value));
                    }
                    flag2 = true;
                }
            }
            if(!flag2){
                item->second.push_back(pair<K,V> (key,value));
            }
        }

    }
    if(!flag1){
        pair<K,V> pair1(key,value);
        list<pair<K,V>> buffList;
        buffList.push_back(pair1);
        store.push_back(pair<int,list<pair<K,V>>> (index_,buffList));
    }
    if(this->size() == array_prime_size_[idx_in_prime_array]-1){
        idx_in_prime_array++;
    }
}

/**
 *
 * @tparam Key
 * @tparam Value
 * @param key
 * @return value for this key
 */
template<typename Key, typename Value>
Value HashTable<Key, Value>::at(K key) {
    int index_ = hash(convert_to_string(key));
    for(auto item = store.begin();item!=store.end();item++){
        if(item->first == index_){

            //if a conflict has collision

            for(auto item2 = item->second.begin();item2!=item->second.end();item2++){
                if(item2->first == key)return item2->second;
            }
        }
    }
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::empty() const {
    return store.size()>0;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::makeEmpty() {
    while(store.size() > 0 ){
        store.pop_back();
    }
    idx_in_prime_array = 0;
}

template<typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
    makeEmpty();
}



template<typename Key, typename Value>
bool HashTable<Key, Value>::contain(K &key) const {
    int index_ = hash(convert_to_string(key));
    for (auto item = store.begin(); item != store.end(); item++) {
        if (item->first == index_) {
            return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
typename HashTable<Key,Value>::Table_iterator HashTable<Key, Value>::begin() {
    return Table_iterator(*this);
}

template<typename Key, typename Value>
typename HashTable<Key,Value>::Table_iterator HashTable<Key, Value>::end() {
    Table_iterator it(*this);
    it.setCurrent(this->store.end());
    return it;
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable<K,V> & other) {
    this->store =other.store;
    this->idx_in_prime_array = other.idx_in_prime_array;
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(HashTable<K, V> && other) noexcept {
    this->store = other.store;
    this->idx_in_prime_array = other.idx_in_prime_array;
}

template<typename Key, typename Value>
HashTable<Key, Value> &HashTable<Key, Value>::operator=(const HashTable<K,V> &other) {
    this->store = other.store;
    this->idx_in_prime_array = other.idx_in_prime_array;
    return *this;
}







