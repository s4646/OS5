#include "activeObject.hpp"
#include <iostream>
#include <unistd.h>

ActiveObject::ActiveObject()
{
    dispatchQueue = new Queue();
    isActive = false;
}
ActiveObject::~ActiveObject() {delete dispatchQueue;}

void ActiveObject::doTask(Item &i)
{
    dispatchQueue->enqueue(i);
}

void busyLoop(ActiveObject *ao)
{
    while(true)
    {
        if (!ao->isActive)
        {
            break;
        }
        if (ao->dispatchQueue->getNumOfItems() == 0)
        {
            continue;
        }

        Item &i = ao->dispatchQueue->getFirst();

        std::cout << (char *)i.getContent() << "\n";

        ao->dispatchQueue->dequeue();
    }
}

void ActiveObject::activate()
{
    isActive = true;
    std::thread loop(busyLoop, this);
    loop.detach();
}
void ActiveObject::deactivate()
{
    isActive = false;
    while(dispatchQueue->getNumOfItems() > 0)
    {
        dispatchQueue->dequeue();
    }
}