#include <stdio.h>
#include <stdlib.h>
struct node *head = 0, *save, *newnode, *temp;

struct node
{
    int data;
    struct node *next;
};

void create(int a)
{
    head = 0;
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
    temp = save;
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

void mergingll()
{
    temp = save;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = head;
}

int main()
{
    int n, val, position;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();
    save = head;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();

    printf("\nAfter merging the linklist is:\n");
    mergingll();
    display();

    return 0;
}