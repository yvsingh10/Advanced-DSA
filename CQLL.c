#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *ptr;

    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = value;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
        rear->next = front;
    }
    else
    {
        ptr->next = front;
        rear->next = ptr;
        rear = ptr;

    }

    printf("Inserted Value:%d\n", value);
}

void dequeue()
{
    struct Node *temp;

    
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    if (front == rear)
    {
        printf("Deleted Value:%d\n", front->data);
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        temp = front;
        printf("Deleted Value:%d\n", temp->data);
        front = front->next;
        rear->next = front;

        free(temp);
    }
}

void display()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    temp = front;
    printf("Queue: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while (temp != front);
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    display();
    
    return 0;
}
