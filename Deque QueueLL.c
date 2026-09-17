#include <stdio.h>
#include <conio.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty()
{
    return front == NULL;
}

void insertFront(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = front;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        front->prev = newnode;
        front = newnode;
    }

    printf("%d inserted at front\n", value);
}

void insertRear(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = rear;

    if (rear == NULL)
    {
        rear = front = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted at rear\n", value);
}

void deleteFront()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    temp = front;
    printf("%d deleted from front\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    temp = rear;
    printf("%d deleted from rear\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

void getFront()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Front element : %d\n", front->data);
    }
}

void getRear()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Rear element : %d\n", rear->data);
    }
}

void display()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    temp = front;
    printf("Deque elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Deque ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display\n");
        printf("8. Check Empty\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                getFront();
                break;

            case 6:
                getRear();
                break;

            case 7:
                display();
                break;

            case 8:
                if (isEmpty())
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
