#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeTypee{
    ItemType info;
    NodeTypee* next;
};
class FullStack{};
class EmptyStack{};

template <class ItemType>
class StackType
{
private:
    NodeTypee<ItemType>* topPtr;
    int length;
public:
    StackType();
    ~StackType();
    int getLength()const;
    bool isFull()const;
    bool isEmpty()const;
    void makeEmpty();
    void push(ItemType);
    void pop();
    ItemType Top();
};
#endif // STACKTYPE_H
#include "StackType.cpp"
