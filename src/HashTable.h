//
// Created by necrobuther on 31.03.2020.
//

#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H

#include <deque>
#include <cstdio>
#include <list>
#include <string>

using namespace std;
template <typename Key,typename Value>
class HashTable {
public:

    class Table_iterator{

    public:
        explicit Table_iterator(HashTable<Key,Value>);

       Table_iterator&operator=(const Table_iterator&);
       Table_iterator& operator++();
       Table_iterator&operator++(int);
      // Table_iterator&operator--();
      // Table_iterator&operator--(int);
       Value operator*();
       //bool operator == (const Table_iterator&);
       //bool operator != (const Table_iterator&);
        void setCurrent(typename deque<pair<int,list<pair<Key,Value>>>>::iterator& other);
        bool operator==(const Table_iterator &rhs) const;

        bool operator!=(const Table_iterator &rhs) const;

     //   ~Table_iterator();

    private:
         typename deque<pair<int,list<pair<Key,Value>>>>::iterator current;
        friend class HashTable<Key,Value>;
    };

    using K = Key;
    using V = Value;

    void insert(pair<K,V> pair1);

    void insert(K key, V value);
    bool contain(K &key) const;
    V at(K key);
    void makeEmpty();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t capacity() const;

   // void operator=(const HashTable<K,V>&);
    HashTable();
  //  HashTable(const HashTable<K,V>&);
   // HashTable(HashTable<K,V>&&) noexcept ;
    ~HashTable();

    Table_iterator begin();
    Table_iterator end();

private:
    size_t idx_in_prime_array;
    deque<pair<int,list<pair<K,V>>>> store;
    int hash(const string &hasher);
   // list<pair<K,V>> matching_index(int find_key);
    string convert_to_string(K key);

    const std::size_t array_prime_size_[23]  { 11, 13, 17, 19, 31, 37, 43, 51, 57, 129, 401,643,
                                               853, 1009, 1069,3271, 3299, 4139, 4463, 4621,
                                               7841, 8719, 9973};
};




#endif //TASK4_HASHTABLE_H
