#pragma once

#include "queue.hpp"
#include <unistd.h>

class ActiveObject
{
    private:
        Queue *dispatchQueue;
        bool isActive;
        std::thread loop;
        void* (*task)(void*);
        ActiveObject* next;

    public:
        ActiveObject();
        ActiveObject(void* (*f)(void*));
        ~ActiveObject();
        void activate();
        void deactivate();
        void setNext(ActiveObject *ao);
        void setTask(void* (*f)(void*));
        void doTask(Item *i);
        
        friend void busyLoop(ActiveObject *ao);
};