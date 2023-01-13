#pragma once

#include <thread>
#include <mutex>
#include <stdexcept>

class Item;

class Queue
{
    private:
        Item *first; // to enter queue
        Item *last;  // to enter queue
        std::mutex m;
        int numOfItems;

    public:
        Queue();
        ~Queue();
        void enqueue(Item *i);
        Item* dequeue();
        int getNumOfItems();
        Item* getFirst();
        Item* getLast();
};

class Item
{
    private:
        void *input;
        void *output;
        Item *next;
        Item *prev;

    public:
        Item();
        Item(void *vp);
        Item(Item *i);
        ~Item();
        void setInput(void *vp);
        void setOutput(void *vp);
        void* getInput();
        void* getOutput();
        void setNext(Item *other);
        void setPrev(Item *other);
    
    friend class Queue;
};