#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    void *content;
    struct Item *next;
    struct Item *prev;
} Item;
Item *initItem();
Item *initItem_c(void *content);
void setContent(Item *self, void *c);
void setNext(Item *self, Item *other);
void setPrev(Item *self, Item *other);
void *getContent(Item *self);


typedef struct Queue
{
    Item *first; // to enter queue
    Item *last;  // to enter queue
    int numOfItems;
} Queue;
Queue *initQueue();
void enqueue(Queue *self, Item *i);
void dequeue(Queue *self);
int getNumOfItems(Queue *self);
Item *getfirst(Queue *self);
Item *getlast(Queue *self);
void freeQueue(Queue *self);