#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head, *tail;

void create(int n)
{
    head = 0;
    struct node *newnode, *temp;
    for (size_t i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->previous = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->previous = temp;
            temp = temp->next;
        }
    }
    tail = newnode;
    tail->next = head;
    head->previous = tail;
}
void display()
{
    struct node *temp;
    temp = head;
    printf("\nthe doubly linklist is: ");
    do
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void inseertAtBeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->previous = 0;
    if (head != 0)
    {
        newnode->previous = tail;
        newnode->next = head;
        head->previous = newnode;
        head = newnode;
        tail->next = head;
    }
}
void inseertAtEnd()
{
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->previous = 0;
    if (head != 0)
    {
        tail->next = newnode;
        newnode->previous = tail;
        tail = newnode;
        tail->next = head;
    }
}
void insertAtPosition(int pos)
{
    struct node *newnode, *temp;
    temp = head;
    int i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->previous = 0;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->previous;
    temp->previous->next = newnode;
    temp->previous = newnode;
    newnode->next = temp;
}
void insertAfterPosition(int pos)
{
    struct node *newnode, *temp;
    temp = head;
    int i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->previous = 0;
    while (i <= pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->previous;
    temp->previous->next = newnode;
    temp->previous = newnode;
    newnode->next = temp;
}
int main()
{
    int num, position;
    printf("how many number you want to enter in Dll: ");
    scanf("%d", &num);
    create(num);
    display();
    printf("\nAt the begining of linklist ");
    inseertAtBeg();
    display();
    printf("\nAt the end of linklist ");
    inseertAtEnd();
    display();
    printf("\nEnter the postion: ");
    scanf("%d", &position);
    insertAtPosition(position);
    display();
    printf("\nInsert After the postion: ");
    scanf("%d", &position);
    insertAfterPosition(position);
    display();

    return 0;
}