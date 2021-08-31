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
void updatell(int value, int pos)
{
    int i = 1;
    temp = head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->data = value;
}

int main()
{
    int n, val, position;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();
    printf("\nenter the position you want to update: \n");
    scanf("%d", &position);
    printf("\nenter the value  \n");
    scanf("%d", &val);
    updatell(val, position);
    display();

    return 0;
}