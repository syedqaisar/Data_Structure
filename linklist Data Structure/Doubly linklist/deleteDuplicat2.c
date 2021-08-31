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

void deleteDuplicateSorted()
{
    struct node *temp, *delete;
    temp = head->next;
    while (temp->next != 0)
    {
        if (temp->data == temp->previous->data)
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete = temp;
            free(delete);
        }
        temp = temp->next;
    }
    if (temp->data == temp->previous->data)
    {
        temp->previous->next = 0;
        free(temp);
    }
}
void deleteDuplicateUnsort()
{
    struct node *temp, *check, *delete;
    check = head;
    while (check != 0)
    {
        temp = check->next;
        while (temp != 0)
        {
            if (check->data == temp->data)
            {
                temp->previous->next = temp->next;
                if (temp->next != 0)
                {
                    temp->next->previous = temp->previous;
                }
                delete = temp;
                free(delete);
            }
            temp = temp->next;
        }
        check = check->next;
    }
}
int main()
{
    int num, position;
    printf("how many number you want to enter in Dll: ");
    scanf("%d", &num);
    create(num);
    display();
    printf("\nAfter deleting the duplicting element from unsorted Dll:\n ");
    deleteDuplicateUnsort();
    display();

    return 0;
}