#include "gtest/gtest.h"
#include "../src/HashTable.h"
#include "../src/HashTable.cpp"
TEST(Constructor,NormalConstructor){
    HashTable<int,int> k;
    k.insert(1,2);
    k.insert(2,3);
    k.insert(3,2);
    EXPECT_EQ(2,k.at(3));
    k.insert(3,4);
    EXPECT_EQ(2,k.at(1));
    EXPECT_EQ(4,k.at(3));
    k.makeEmpty();
    EXPECT_EQ(0,k.size());
}
TEST(Iterator,Norm_Iterator){
    HashTable<int,int> k;
    k.insert(1,2);
    k.insert(2,3);
    k.insert(3,4);
    auto it = k.begin();
    EXPECT_EQ(2,*it);
    ++it;
    EXPECT_EQ(3,*it);

}