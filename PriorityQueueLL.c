#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

void enqueue()
{
    int value, priority;
    struct node *ptr, *temp;

    ptr = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &priority);

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

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Priority queue is empty.\n");
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
        printf("Priority queue is empty.\n");
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
        printf("Priority queue is empty.\n");
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
    int choice;

    while (1)
    {
        printf("\n--- PRIORITY QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
