#include "queue.hpp"

/**
 * START ITEM
*/
Item::Item()
{
    input = nullptr;
    output = nullptr;
    prev = nullptr;
    next = nullptr;
}
Item::Item(void *vp)
{
    input = vp;
    output = nullptr;
    prev = nullptr;
    next = nullptr;    
}
Item::Item(Item *i)
{
    input = i->input;
    output = i->output;
    prev = i->prev;
    next = i->next;
}
Item::~Item() {}
void Item::setInput(void *vp) {input = vp;}
void Item::setOutput(void *vp) {output = vp;}
void* Item::getInput() {return input;}
void* Item::getOutput() {return output;}
void Item::setNext(Item *n) {next = n;}
void Item::setPrev(Item *p) {prev = p;}
/**
 * END ITEM
*/

/**
 * START QUEUE
*/
Queue::Queue()
{
    numOfItems = 0;
    first = nullptr;
    last = nullptr;
}
Queue::~Queue()
{
    delete first;
    delete last;
}
int Queue::getNumOfItems() {return numOfItems;}
Item*Queue::getLast() {return last;}
Item* Queue::getFirst() {return first;}


void Queue::enqueue(Item *i)
{
    m.lock();
    if (numOfItems == 0)
    {
        last  = i;
        first = i;
    }
    else if (numOfItems == 1)
    {
        last = i;
        last->setPrev(first);
        first->setNext(last);
    }
    else
    {
        i->setPrev(last);
        last->setNext(i);
        last = i;
    }
    numOfItems++;
    m.unlock();
}

Item* Queue::dequeue()
{
    m.lock();
    Item *temp = nullptr;
    if (numOfItems > 1)
    {
        temp = first;
        first = temp->next;
        temp->setNext(nullptr);
        temp->setPrev(nullptr);
    }
    else if (numOfItems == 1)
    {
        temp = new Item(first);
        temp->setNext(nullptr);
        temp->setPrev(nullptr);
        
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        throw std::runtime_error("dequeue empty queue is not possible!\n");
    }
    numOfItems--;
    m.unlock();

    return temp;
}
/**
 * END QUEUE
*/