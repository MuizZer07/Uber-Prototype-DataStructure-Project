#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

#include "StackType.h"

template <class ItemType>
StackType<ItemType>::StackType()
{
   topPtr = NULL;
   length = 0;
}
template <class ItemType>
StackType<ItemType>::~StackType()
{
    NodeTypee<ItemType>* temp;
    while(topPtr != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }

}
template <class ItemType>
void StackType<ItemType>::makeEmpty()
{
    NodeTypee<ItemType>* temp;
    while(topPtr != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
    length = 0;
}
template <class ItemType>
bool StackType<ItemType>::isEmpty()const
{
    return (topPtr == NULL);
}
template <class ItemType>
int StackType<ItemType>::getLength()const
{
    return length;
}
template <class ItemType>
bool StackType<ItemType>::isFull()const
{
    NodeTypee<ItemType>* newNode;
    try{
        newNode = new NodeTypee<ItemType>;
        delete newNode;
        return false;
    }catch(bad_alloc ex)
    {
        return true;
    }
}
template <class ItemType>
void StackType<ItemType>::push(ItemType item)
{
    if(isFull()) throw FullStack();
    else{
        NodeTypee<ItemType>* location;
        location = new NodeTypee<ItemType>;
        location->info = item;
        location->next = topPtr;
        topPtr = location;
    }
    length++;
}
template <class ItemType>
void StackType<ItemType>::pop()
{
    if(isEmpty()) throw EmptyStack();
    else{
        NodeTypee<ItemType>* temp;
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
    length--;
}
template <class ItemType>
ItemType StackType<ItemType>::Top()
{
    if(isEmpty()) throw EmptyStack();
    else return topPtr->info;
}
#endif // STACKTYPE_CPP
