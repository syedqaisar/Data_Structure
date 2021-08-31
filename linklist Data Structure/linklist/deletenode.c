#include <stdio.h>
#include <stdlib.h>
struct node *head = 0, *newnode, *temp;

struct node
{
    int data;
    struct node *next;
};

void create(int a)
{

    for (size_t i = 0; i < a; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != 0)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}
void display()
{
    temp = head;
    if (temp == 0)
    {
        printf("the Linklist is empty.");
    }
    else
    {
        printf("the given linklist is:");
        while (temp != 0)
        {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
    }
}
void insertAtBegining(int beg)
{
    for (size_t i = 0; i < beg; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
    }
}
void insertAtend(int e)
{
    for (size_t i = 0; i < e; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        temp = head;
        while (temp->next != 0)
            temp = temp->next;
        temp->next = newnode;
    }
}
void insertAtposition(int pos, int num)
{
    for (size_t i = 1; i <= num; i++)
    {
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d", &newnode->data);
        for (size_t i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteAtbegining()
{
    temp = head;
    head = temp->next;
    free(temp);
}
void deleteAtend()
{
    struct node *delete;
    temp = head;
    while (temp->next->next != 0)
    {
        temp = temp->next;
    }
    delete = temp->next;
    temp->next = 0;
    free(delete);
}
void deleteAtend2()
{
    temp = head;
    struct node *previous;
    while (temp->next != 0)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = 0;
    free(temp);
}

void deleteAtposition(int pos)
{
    struct node *delete;
    temp = head;
    for (size_t i = 2; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
}
int main()
{
    int n, i, begin, end, position, mid, delete, deletePosition;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();
    printf("\nhow many number you want to enter at begining: ");
    scanf("%d", &begin);
    insertAtBegining(begin);
    display();
    printf("\nhow many number you want to enter at end: ");
    scanf("%d", &end);
    insertAtend(end);
    display();
    printf("\nhow many number you want to enter at the mid:\n");
    scanf("%d", &mid);
    printf("\nIn which place you want to insert: ");
    scanf("%d", &position);
    insertAtposition(position, mid);
    display();
    printf("\nif you to delete node at begining plz enter '1':\n");
    scanf("%d", &delete);
    if (delete == 1)
        deleteAtbegining();
    display();
    printf("\nif you to delete node at end plz enter '1':\n");
    scanf("%d", &delete);
    if (delete == 1)
        deleteAtend2();
    display();

    printf("\nAt what position you want to delete node:\n");
    scanf("%d", &deletePosition);
    deleteAtposition(deletePosition);
    display();

    return 0;
}