#include "activeObject.hpp"

ActiveObject::ActiveObject()
{
    dispatchQueue = new Queue();
    isActive = false;
    next = nullptr;
}
ActiveObject::ActiveObject(void* (*f)(void*))
{
    dispatchQueue = new Queue();
    isActive = false;
    task = f;
    next = nullptr;
}
ActiveObject::~ActiveObject() {delete dispatchQueue;}

void ActiveObject::setNext(ActiveObject *ao) {next = ao;}

void ActiveObject::setTask(void* (*f)(void*)) {task = f;}
void ActiveObject::doTask(Item *i)
{
    usleep(100);
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

        Item *i = ao->dispatchQueue->getFirst();
        
        i->setOutput(ao->task(i->getInput()));

        if (ao->next == nullptr)
        {
            delete ao->dispatchQueue->dequeue();
        }
        else
        {
            ao->next->doTask(ao->dispatchQueue->dequeue());
        }
    }
}

void ActiveObject::activate()
{
    isActive = true;
    loop = std::thread(busyLoop, this);
}
void ActiveObject::deactivate()
{
    isActive = false;
    loop.join();
    while(dispatchQueue->getNumOfItems() > 0)
    {
        delete dispatchQueue->dequeue();
    }
}