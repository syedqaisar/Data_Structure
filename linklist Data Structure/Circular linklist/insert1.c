#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} * head;
void creat(int num)
{
    head = 0;
    struct node *newnod, *temp;
    for (size_t i = 0; i < num; i++)
    {
        newnod = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnod->data);
        newnod->next = 0;
        if (head == 0)
        {
            head = temp = newnod;
        }
        else
        {
            temp->next = newnod;
            temp = newnod;
        }
    }
    newnod->next = head;
}
void displayone()
{
    struct node *temp;
    temp = head;
    printf("\nthe circular linklist is: \n");
    printf("%d, ", temp->data);
    temp = temp->next;
    while (temp != head)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    printf("\nthe circular linklist is: \n");
    while (temp->next != head)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d, ", temp->data);
}
void insertAtBeg()
{
    struct node *newnod, *temp;
    temp = head;
    newnod = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnod->data);

    while (temp->next != head)
    {
        temp = temp->next;
    }
    // temp = temp->next;
    newnod->next = head;
    head = newnod;
    temp->next = head;
}
void insertAtEnd()
{
    struct node *newnod, *temp;
    temp = head;
    newnod = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnod->data);
    newnod->next = 0;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnod;
    newnod->next = head;
}

void insertAtposition(int pos)
{
    int i = 1;
    struct node *newnod, *temp;
    temp = head;
    newnod = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnod->data);
    newnod->next = 0;
    while (i < pos - 1)
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