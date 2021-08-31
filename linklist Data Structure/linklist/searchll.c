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
        printf("\nthe given linklist is:");
        while (temp != 0)
        {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
    }
}
int lengthOflist()
{
    int count = 0;
    temp = head;
    if (temp == 0)
    {
        return count;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
            count++;
        }
        count++;
    }
    return count;
}
int searchll(int value)
{
    temp = head;
    while (temp->next != 0)
    {
        if (temp->data == value)
        {
            printf("the value is found ");
            return 0;
        }
        temp = temp->next;
    }
    printf("the value is not found ");
}

int main()
{
    int n, i, begin, val, end, position, mid, delete, deletePosition;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();
    printf("\nenter the value for searching in linklist: \n");
    scanf("%d", &val);
    searchll(val);
    display();

    return 0;
}