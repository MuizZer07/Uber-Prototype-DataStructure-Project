#ifndef QUEUETYPE_CPP
#define QUEUETYPE_CPP

#include "QueueType.h"

template <class ItemType>
QueueType<ItemType>::QueueType()
{
    rear = NULL;
    front = NULL;
    length = 0;
}
template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    NodeTypeee<ItemType>* temp;
    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}
template <class ItemType>
void QueueType<ItemType>::makeEmpty()
{
    NodeTypeee<ItemType>* temp;
    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    length = 0;
}
template <class ItemType>
bool QueueType<ItemType>::isEmpty()const
{
    return (front == NULL);
}
template <class ItemType>
int QueueType<ItemType>::getLength()const
{
    return length;
}
template <class ItemType>
bool QueueType<ItemType>::isFull()const
{
    NodeTypeee<ItemType>* location;
    try{
        location = new NodeTypeee<ItemType>;
        delete location;
        return false;
    }catch(bad_alloc ex)
    {
        return true;
    }
}
template <class ItemType>
void QueueType<ItemType>::EnQueue(ItemType item)
{
    if(isFull()) throw FullQueue();
    else{
        NodeTypeee<ItemType>* newNode;
        newNode = new NodeTypeee<ItemType>;
        newNode->info = item;
        newNode->next = NULL;

        if(rear == NULL) front = newNode;
        else {
            rear->next = newNode;
            newNode = rear;
        }
    }
    length++;
 }
template <class ItemType>
void QueueType<ItemType>::Dequeue()
{
    ItemType item;
    if(isEmpty()) throw EmptyQueue();
    else{
        NodeTypeee<ItemType>* temp;

        temp = front;
        item = front->info;
        front = front->next;
        if(front == NULL) rear = NULL;
        delete temp;
    }
    length--;
}
#endif // QUEUETYPE_CPP

