#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

void enqueue(int value, int priority)
{
    struct node *ptr, *temp;

    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = value;
    ptr->priority = priority;
    ptr->next = NULL;

    if (front == NULL || priority > front->priority)
    {
        ptr->next = front;
        front = ptr;
    }
    else
    {
        temp = front;

        while (temp->next != NULL &&
               temp->next->priority >= priority)
        {
            temp = temp->next;
        }

        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Priority queue is empty\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Priority queue is empty\n");
        return;
    }

    printf("Highest priority element: %d\n", front->data);
    printf("Priority: %d\n", front->priority);
}

void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Priority queue is empty\n");
        return;
    }

    temp = front;

    while (temp != NULL)
    {
        printf("Data: %d  Priority: %d\n",
               temp->data, temp->priority);

        temp = temp->next;
    }
}

int main()
{
    enqueue(30, 5);
    enqueue(44, 1);
    enqueue(23, 8);

    dequeue();

    peek();

    display();

    return 0;
}
