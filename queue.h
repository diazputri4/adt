#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "node.h"

typedef struct {
    address front;
    address rear;
} Queue;

void createQueue(Queue *q);
boolean isEmpty(Queue q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void printQueue(Queue q);

#endif
