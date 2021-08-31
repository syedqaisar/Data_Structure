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
        printf("the given linklist is:");
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
void midOfll(int pos)
{
    temp = head;
    int n = pos / 2;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    if (pos % 2 == 0)
    {
        printf("\nthere are two value at mid becouse the linklist is even. \n");
        printf("the mid values are: %d,  %d \n", temp->data, temp->next->data);
    }
    else
    {
        printf("\nthe mid value is: %d \n", temp->next->data);
    }
}

int main()
{
    int n, i, begin, end, position, mid, delete, deletePosition;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();
    int size = lengthOflist();
    printf("\nthe length of linklist is: %d", size);
    midOfll(size);

    return 0;
}