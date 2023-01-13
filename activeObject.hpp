#pragma once

#include "queue.hpp"

class ActiveObject
{
    private:
        Queue *dispatchQueue;
        bool isActive;
        std::thread loop;
        void* (*task)(void*);

    public:
        ActiveObject();
        ActiveObject(void* (*f)(void*));
        ~ActiveObject();
        void activate();
        void deactivate();
        void setTask(void* (*f)(void*));
        void doTask(Item *i);
        
        friend void busyLoop(ActiveObject *ao);
};