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
TEST(Copy,NormCopy){
    HashTable<int,int> k;
    k.insert(1,2);
    k.insert(2,3);
    k.insert(3,4);
    HashTable<int,int> k2(k);
    EXPECT_EQ(2,k2.at(1));
    EXPECT_EQ(3,k2.at(2));
}
TEST(Contain,NO_CONTAIN){
    HashTable<int,int> k;
    k.insert(1,2);
    k.insert(2,3);
    k.insert(3,4);
    EXPECT_FALSE(k.contain(5));
    EXPECT_TRUE(k.contain(2));
}
TEST(AT,THROW_EXCEPTION){
    HashTable<int,int> k;
    k.insert(1,2);
    k.insert(2,3);
    k.insert(3,4);
    EXPECT_EQ(3,k.at(2));
    EXPECT_THROW(k.at(55),exception);

}