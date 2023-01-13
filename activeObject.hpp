#pragma once

#include "queue.hpp"

class ActiveObject
{
    private:
        Queue *dispatchQueue;
        bool isActive;
        std::thread loop;

    public:
        ActiveObject();
        ~ActiveObject();
        void activate();
        void deactivate();
        void doTask(Item &i);
        
        friend void busyLoop(ActiveObject *ao);
};