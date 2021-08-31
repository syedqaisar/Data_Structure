#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} * tail, *head;
void creat(int num)
{
    tail = 0;
    struct node *newnod, *temp;
    for (size_t i = 0; i < num; i++)
    {
        newnod = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnod->data);
        newnod->next = 0;
        if (tail == 0)
        {
            tail = newnod;
            tail->next = newnod;
        }
        else
        {
            newnod->next = tail->next;
            tail->next = newnod;
            tail = newnod;
        }
    }
}
void display()
{
    struct node *temp;
    temp = tail;
    printf("\nthe circular linklist is: \n");
    while (temp->next != tail)
    {
        printf("%d, ", temp->next->data);
        temp = temp->next;
    }
    printf("%d, ", temp->next->data);
}

void insertAtBeg()
{
    struct node *newnod, *temp;
    temp = tail;
    newnod = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnod->data);
    temp = tail->next;
    tail->next = newnod;
    newnod->next = temp;
}
void insertAtEnd()
{
    struct node *newnod;
    newnod = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnod->data);
    newnod->next = 0;
    newnod->next = tail->next;
    tail->next = newnod;
    tail = newnod;
}

void insertAtposition(int pos)
{
    int i = 1;
    struct node *newnod, *temp;
    temp = tail;
    newnod = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnod->data);
    newnod->next = 0;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnod->next = temp->next;
    temp->next = newnod;
}
int main()
{
    int n, position;
    printf("how many number you want to enter in crcular linklist: ");
    scanf("%d", &n);
    creat(n);
    display();
    printf("\nInsert at beging ");
    insertAtBeg();
    display();
    printf("\nInsert at end ");
    insertAtEnd();
    display();
    printf("\nEnter the position: ");
    scanf("%d", &position);
    printf("\nInsert at position ");
    insertAtposition(position);
    display();
    return 0;
}