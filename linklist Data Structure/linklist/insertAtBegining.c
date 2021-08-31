#include <stdio.h>
#include <stdlib.h>
struct node *head = 0, *newnode, *temp;

struct node
{
    int data;
    struct node *next;
};

void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
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
        printf("the given linklist is:\n");
        while (temp != 0)
        {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
    }
}
void insertAtBegining()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data:");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
int main()
{
    int n, i, begin;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        create();
    }
    display();
    printf("\nhow many number you want to enter at the begining:\n");
    scanf("%d", &begin);
    for (i = 0; i < begin; i++)
    {
        insertAtBegining();
    }

    display();

    return 0;
}