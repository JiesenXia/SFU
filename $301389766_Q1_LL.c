#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int number;
    struct node *next;
} node;


node *enqueue(int element, node *temp);
node *dequeue(int n, node *temp);
void display(node *temp);
void destroy_queue(node *temp);

int main()
{
    node *queue = NULL;

    // add some elements to queue
    for (int i = 0; i < 5; i++)
    {
        queue = enqueue((i + 1), queue);
    }


    // display queue
    display(queue);

    // dequeue 2 elements from queue
    printf("Removing two elements from queue...\n");
    queue = dequeue(2, queue);

    //display queue
    display(queue);

    // free memory
    destroy_queue(queue);

}

node *enqueue(int element, node *temp)
{
    node *newElement = malloc(sizeof(node));
    node *head = temp;
    if (newElement == NULL)
    {
        fprintf(stderr, "No memory for the new queue element");
        return temp;
    }

    newElement->number = element;
    newElement->next = NULL;

    if (head == NULL)
    {
        return newElement;
    }
    else
    {
        while ((temp->next) != NULL)
        {
            temp = temp->next;
        }
        temp->next = newElement;
    }
    return head;
}

node *dequeue(int n, node *temp)
{
    node *aux;
    for (int i = 0; i < n; i++)
    {
        if (!temp)
        {
            fprintf(stderr,"No elements to remove!");
            return temp;
        }
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    return temp;
}

void display(node *temp)
{
    while (temp)
    {
        printf("Elements in queue are: %i\n", temp->number);
        temp = temp->next;
    }
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
