#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

#include "SortedType.h"
#include "Driver.h"

template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listdata = NULL;
}
template <class ItemType>
SortedType<ItemType>::~SortedType()
{
   NodeType<ItemType>* temp;
    while(listdata != NULL)
    {
        temp = listdata;
        listdata = listdata->next;
        delete temp;
    }
}
template <class ItemType>
void SortedType<ItemType>::makeEmpty()
{
    NodeType<ItemType>* temp;
    while(listdata != NULL)
    {
        temp = listdata;
        listdata = listdata->next;
        delete temp;
    }
}
template <class ItemType>
int SortedType<ItemType>::getLength()const
{
    return length;
}
template <class ItemType>
ItemType SortedType<ItemType>::getItem(ItemType item, bool found)
{
    NodeType<ItemType>* location = listdata;
    bool moretosearch = (location != NULL);
    found = false;

    while(moretosearch && !found)
    {
        switch(item.CompareTo(location->info))
        {
        case LESS:
            moretosearch = false;
            break;
        case GREATER:
            location = location->next;
            moretosearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}
template <class ItemType>
void SortedType<ItemType>::PutBYRating(ItemType item)
{
   NodeType<ItemType>* location = listdata;
    NodeType<ItemType>* predLoc = NULL;
    NodeType<ItemType>* newNode;

    bool moretosearch = (location != NULL);
    while(moretosearch)
    {
        switch(item.CompareBYrating(location->info))
        {
        case EQUAL:
        case LESS:
            predLoc = location;
            location = location->next;
            moretosearch = (location != NULL);
            break;

        case GREATER:
            moretosearch = false;
            break;
        }
    }
    newNode =  new NodeType<ItemType>;
    newNode->info = item;

    if(predLoc == NULL){
        newNode->next = listdata;
        listdata = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
template <class ItemType>
void SortedType<ItemType>::PutBYearnings(ItemType item)
{
    NodeType<ItemType>* location = listdata;
    NodeType<ItemType>* predLoc = NULL;
    NodeType<ItemType>* newNode;

    bool moretosearch = (location != NULL);
    while(moretosearch)
    {
        switch(item.CompareBYearnings(location->info))
        {
        case EQUAL:
        case LESS:
            predLoc = location;
            location = location->next;
            moretosearch = (location != NULL);
            break;

        case GREATER:
            moretosearch = false;
            break;
        }
    }
    newNode =  new NodeType<ItemType>;
    newNode->info = item;

    if(predLoc == NULL){
        newNode->next = listdata;
        listdata = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::PutBYfine(ItemType item)
{
    NodeType<ItemType>* location = listdata;
    NodeType<ItemType>* predLoc = NULL;
    NodeType<ItemType>* newNode;

    bool moretosearch = (location != NULL);
    while(moretosearch)
    {
        switch(item.CompareBYfine(location->info))
        {
            case EQUAL:
            case LESS:
            predLoc = location;
            location = location->next;
            moretosearch = (location != NULL);
            break;

        case GREATER:
            moretosearch = false;
            break;
        }
    }
    newNode =  new NodeType<ItemType>;
    newNode->info = item;

    if(predLoc == NULL){
        newNode->next = listdata;
        listdata = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::putItem(ItemType item)
{
    NodeType<ItemType>* location = listdata;
    NodeType<ItemType>* predLoc = NULL;
    NodeType<ItemType>* newNode;

    bool moretosearch = (location != NULL);
    while(moretosearch)
    {
        switch(item.CompareTo(location->info))
        {
        case LESS:
            moretosearch = false;
            break;
        case GREATER:
            predLoc = location;
            location = location->next;
            moretosearch = (location != NULL);
            break;
        }
    }
    newNode =  new NodeType<ItemType>;
    newNode->info = item;

    if(predLoc == NULL){
        newNode->next = listdata;
        listdata = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
template <class ItemType>
void SortedType<ItemType>::deleteItem(ItemType item)
{
    NodeType<ItemType>* location = listdata;
    NodeType<ItemType>* temp;

    if(item.CompareTo(location->info)==EQUAL)
    {
        temp = listdata;
        listdata = listdata->next;
    }
    else
    {
        while(item.CompareTo(location->next->info) != EQUAL) location = location->next;

        temp = location->next;
        location->next = location->next->next;
    }
    delete temp;
    length--;
}

template <class ItemType>
void SortedType<ItemType>::putRandom(ItemType item)
{
    NodeType<ItemType>* location;
    location = new NodeType<ItemType>;
    location->info = item;
    location->next=listdata;
    listdata = location;
    length++;
}
template <class ItemType>
bool SortedType<ItemType>::isFull()const
{
    NodeType<ItemType>* newNode;
    try{
        newNode = new NodeType<ItemType>;
        delete newNode;
        return false;
    }catch(bad_alloc ex){
        return true;
    }
}
template <class ItemType>
void SortedType<ItemType>::resetList()
{
    currentPos = NULL;
}
template <class ItemType>
void SortedType<ItemType>::setHighestLength(int x)
{
    if(length > x)
    length = x;
}
template <class ItemType>
ItemType SortedType<ItemType>::getNextItem()
{
    ItemType item;
    if(currentPos == NULL)
        currentPos = listdata;
    item = currentPos->info;
    currentPos = currentPos->next;
    return item;
}
template <class ItemType>
void SortedType<ItemType>::printList(ofstream& out)
{
    resetList();
    for(int i=0; i<getLength(); i++)
    {
        getNextItem().print(out);
    }
}
template <class ItemType>
void SortedType<ItemType>::printUpdatedList(fstream& out)
{
    resetList();
    for(int i=0; i<getLength(); i++)
    {
        getNextItem().printUpdate(out);
    }
}
#endif // SORTEDTYPE_CPP
