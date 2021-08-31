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
void deleteAtBeg()
{
    struct node *temp, *delete;
    delete = temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    free(delete);
    temp->next = head;
}
void deleteAtEnd()
{
    struct node *temp, *delete;
    delete = temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp = temp->next;
    free(temp);
}

void deleteAtposition(int pos)
{
    int i = 1;
    struct node *temp, *delete;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
}
int main()
{
    int n, position;
    printf("how many number you want to enter in crcular linklist: ");
    scanf("%d", &n);
    creat(n);
    display();
    printf("\ndelete at beging ");
    deleteAtBeg();
    display();
    printf("\ndelete at end ");
    deleteAtEnd();
    display();
    printf("\nEnter the position: ");
    scanf("%d", &position);
    printf("\nInsert at position ");
    deleteAtposition(position);
    display();
    return 0;
}