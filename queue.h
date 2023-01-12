#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

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
    pthread_mutex_t lock;
    int numOfItems;
} Queue;
Queue *initQueue();
void *enqueue(void *a);
void *dequeue(void *a);
int getNumOfItems(Queue *self);
Item *getfirst(Queue *self);
Item *getlast(Queue *self);
void freeQueue(Queue *self);

typedef struct q_args
{
    Queue *self;
    Item *i;
} q_args;