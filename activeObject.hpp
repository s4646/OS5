#pragma once

#include "queue.hpp"

class ActiveObject
{
    private:
        Queue *dispatchQueue;
        bool isActive;

    public:
        ActiveObject();
        ~ActiveObject();
        void activate();
        void deactivate();
        void doTask(Item &i);
        
        friend void busyLoop(ActiveObject *ao);
};