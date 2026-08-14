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
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    // Queue is empty
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;

        rear->next = front;
    }
    else
    {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

void dequeue()
{
    struct Node *temp;

    // Queue is empty
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    // Only one node
    if (front == rear)
    {
        printf("%d deleted\n", front->data);

        free(front);

        front = NULL;
        rear = NULL;
    }
    else
    {
        temp = front;

        printf("%d deleted\n", front->data);

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

    } while (temp != front);

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
