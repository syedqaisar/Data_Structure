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
void displayReverse()
{
    struct node *temp;
    temp = head;
    printf("\nthe doubly linklist is: ");
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    while (temp != 0)
    {
        printf("%d, ", temp->data);
        temp = temp->previous;
    }
}
int main()
{
    int num;
    printf("how many number you want to enter in Dll: ");
    scanf("%d", &num);
    create(num);

    displayReverse();
    return 0;
}