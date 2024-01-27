#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue)
{
    return queue->front == -1;
}

void Enqueue(Queue* queue, int item)
{
    queue->array[++queue->rear] = item;
    if (isEmpty(queue))
        ++queue->front;
}

int Dequeue(Queue* queue)
{
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;

    return item;
}

void destroy_queue(node *temp)
{
    node *aux = temp;
    while (temp)
    {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
}
