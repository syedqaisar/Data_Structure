
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

void deleteDuplicateUnsort()
{
    struct node *check, *nextnode, *delete;
    check = temp = head;
    while (check->next != 0)
    {
        temp = check;
        nextnode = temp->next;
        while (nextnode != 0)
        {
            if (check->data == nextnode->data)
            {
                delete = temp->next;
                nextnode = nextnode->next;
                temp->next = nextnode;
            }
            else
            {
                temp = temp->next;
                nextnode = nextnode->next;
            }
        }
        check = check->next;
    }
}

int main()
{
    int n, val, position;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();

    printf("\nAfter delete from unsorting linklist: \n");
    deleteDuplicateUnsort();
    display();

    return 0;
}