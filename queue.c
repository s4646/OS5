#include "queue.h"

/**
 * START ITEM
*/
void setContent(Item *self, void *content) {self->content = content;}
void setNext(Item *self, Item *next) {self->next = next;}
void setPrev(Item *self, Item *prev) {self->prev = prev;}
void *getContent(Item *self) {return self->content;}

Item *initItem()
{
    Item *i = (Item *)malloc(sizeof(Item));
    i->content = NULL;
    i->prev = NULL;
    i->next = NULL;
    return i;
}

Item *initItem_c(void *c)
{
    Item *i = (Item *)malloc(sizeof(Item));
    i->content = c;
    i->prev = NULL;
    i->next = NULL;
    return i;
}
/**
 * END ITEM
*/

/**
 * START QUEUE
*/
int getNumOfItems(Queue *self) {return self->numOfItems;}
Item *getlast(Queue *self) {return self->last;}
Item *getfirst(Queue *self) {return self->first;}

void *enqueue(void *a)
{
    Queue *self = ((q_args *)a)->self;
    Item *i = ((q_args *)a)->i;

    pthread_mutex_lock(&(self->lock));      /* lock */
    if (self->numOfItems == 0)
    {
        self->last = i;
        self->first = i;
    }
    else if (self->numOfItems == 1)
    {
        self->last = i;
        setNext(self->last, self->first);
        setPrev(self->first, self->last);
    }
    else
    {
        setNext(i, self->last);
        setPrev(self->last, i);
        self->last = i;
    }
    self->numOfItems++;
    pthread_mutex_unlock(&(self->lock));    /* unlock */

    return NULL;
}

void *dequeue(void *a)
{
    Queue *self = ((q_args *)a)->self;

    pthread_mutex_lock(&(self->lock));      /* lock */
    if (getNumOfItems(self) > 1)
    {
        Item *temp = getfirst(self);
        setNext(temp->prev, NULL);
        self->first = temp->prev;
        free(temp);
        self->numOfItems--;
    }
    else if (getNumOfItems(self) == 1)
    {
        Item *temp = getfirst(self);
        self->last = NULL;
        self->first = NULL;
        free(temp);
        self->numOfItems--;
    }
    else
    {
        printf("dequeue empty queue is not possible!\n");
    }
    pthread_mutex_unlock(&(self->lock));    /* unlock */

    return NULL;
}

Queue *initQueue()
{
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->last = NULL;
    q->first = NULL;
    q->numOfItems = 0;
    if (pthread_mutex_init(&(q->lock), NULL) != 0) // init lock
    {
        printf("mutex init has failed\n");
        exit(1);
    }
    return q;
}

void freeQueue(Queue *self)
{
    q_args a = {self, NULL};

    int items = getNumOfItems(self);
    for (size_t i = 0; i < items; i++)
    {
        dequeue(&a);
    }

    pthread_mutex_destroy(&(self->lock)); // destroy lock
    free(self);
}
/**
 * END QUEUE
*/