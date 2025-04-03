#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

boolean isEmpty(Queue q) {
    return (q.front == NULL);
}

void enqueue(Queue *q, int data) {
    address newNode = (address)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->info = data;
        newNode->next = NULL;
        if (isEmpty(*q)) {
            q->front = newNode;
            q->rear = newNode;
        } else {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    } else {
        printf("Gagal menambahkan antrian, memori penuh!\n");
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(*q)) {
        address temp = q->front;
        int data = temp->info;
        q->front = q->front->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
        return data;
    }
    printf("Antrian kosong, tidak bisa dequeue!\n");
    return -1;
}

void printQueue(Queue q) {
    address current = q.front;
    if (current == NULL) {
        printf("Antrian kosong!\n");
    } else {
        while (current != NULL) {
            printf("%d -> ", current->info);
            current = current->next;
        }
        printf("NULL\n");
    }
}
