#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeTypeee{
    ItemType info;
    NodeTypeee* next;
};
class FullQueue{};
class EmptyQueue{};

template <class ItemType>
class QueueType
{
private:
    NodeTypeee<ItemType>* front;
    NodeTypeee<ItemType>* rear;
    int length;
public:
    QueueType();
    ~QueueType();
    void makeEmpty();
    int getLength()const;
    bool isFull()const;
    bool isEmpty()const;
    void EnQueue(ItemType);
    void Dequeue();
};

#endif // QUEUETYPE_H
#include "QueueType.cpp"

