//
// Created by necrobuther on 31.03.2020.
//

#include <sstream>
#include "HashTable.h"
template<typename Key, typename Value>
HashTable<Key, Value>::HashTable():capacity{11},store() {}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t _capacity):capacity{_capacity},store() {}

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
    return store.size();
}



template<typename Key, typename Value>
void HashTable<Key, Value>::insert(pair<K, V> pair1) {
     insert(pair1.first,pair1.second);
}

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
                        item->second.erase(buff_LItr);
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

}

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






