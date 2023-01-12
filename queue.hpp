#pragma once

#include <thread>
#include <stdexcept>

class Item;

class Queue
{
    private:
        Item *first; // to enter queue
        Item *last;  // to enter queue
        int numOfItems;

    public:
        Queue();
        ~Queue();
        void enqueue(Item &i);
        void dequeue();
        int getNumOfItems();
        Item &getFirst();
        Item &getLast();
};

class Item
{
    private:
        void *content;
        Item *next;
        Item *prev;

    public:
        Item();
        Item(void *content);
        ~Item();
        void setContent(void *c);
        void setNext(Item *other);
        void setPrev(Item *other);
        void *getContent();
    
    friend class Queue;
};