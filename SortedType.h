#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class SortedType
{
private:
    NodeType<ItemType>* listdata;
    NodeType<ItemType>* currentPos;
    int length;
public:
    SortedType();
    ~SortedType();
    void makeEmpty();
    int getLength()const;
    void setHighestLength(int);
    ItemType getItem(ItemType, bool);
    bool isFull()const;
    void putRandom(ItemType);
    void putItem(ItemType);
    void PutBYRating(ItemType);
    void PutBYfine(ItemType);
    void PutBYearnings(ItemType);
    void deleteItem(ItemType);
    void resetList();
    ItemType getNextItem();
    void printList(ofstream&);
    void printUpdatedList(fstream&);
};
#endif // SORTEDTYPE_H
#include "SortedType.cpp"

