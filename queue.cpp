#include "queue.hpp"

/**
 * START ITEM
*/
Item::Item()
{
    content = nullptr;
    prev = nullptr;
    next = nullptr;
}
Item::Item(void *c)
{
    content = c;
    prev = nullptr;
    next = nullptr;    
}
Item::~Item() {}
void Item::setContent(void *c) {content = c;}
void Item::setNext(Item *n) {next = n;}
void Item::setPrev(Item *p) {prev = p;}
void *Item::getContent() {return content;}
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
Queue::~Queue() {}
int Queue::getNumOfItems() {return numOfItems;}
Item &Queue::getLast() {return *last;}
Item &Queue::getFirst() {return *first;}


void Queue::enqueue(Item &i)
{
    if (numOfItems == 0)
    {
        last  = &i;
        first = &i;
    }
    else if (numOfItems == 1)
    {
        last = &i;
        last->setPrev(first);
        first->setNext(last);
    }
    else
    {
        i.setPrev(last);
        last->setNext(&i);
        last = &i;
    }
    numOfItems++;
}

void Queue::dequeue()
{
    if (numOfItems > 1)
    {
        Item &temp = getFirst();
        first = temp.next;
        temp.setNext(nullptr);
        // temp.~Item();
        numOfItems--;
    }
    else if (numOfItems == 1)
    {
        // Item &temp = getFirst();
        last = NULL;
        first = NULL;
        // temp.~Item();
        numOfItems--;
    }
    else
    {
        throw std::runtime_error("dequeue empty queue is not possible!\n");
    }
}
/**
 * END QUEUE
*/