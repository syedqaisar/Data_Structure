#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head;

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
}
void display()
{
    struct node *temp;
    temp = head;
    printf("\nthe doubly linklist is: ");
    while (temp != 0)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

void deletefromBeg()
{
    struct node *temp;
    temp = head;
    head = temp->next;
    free(temp);
}
void deletefromEnd()
{
    struct node *temp;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->previous->next = 0;
    free(temp);
}
void deletefromPosition(int pos)
{
    struct node *temp;
    temp = head;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    free(temp);
}
int main()
{
    int num, position;
    printf("how many number you want to enter in Dll: ");
    scanf("%d", &num);
    create(num);
    display();
    printf("\nAt the begining of linklist ");
    deletefromBeg();
    display();
    printf("\nAt the end of linklist ");
    deletefromEnd();
    display();
    printf("\nEnter the postion: ");
    scanf("%d", &position);
    deletefromPosition(position);
    display();

    return 0;
}