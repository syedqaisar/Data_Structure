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

int lengthOflist1()
{
    int count = 0;
    temp = head;
    if (temp == 0)
    {
        return count;
    }
    else
    {
        while (temp != 0)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}
int powerOfll(int n)
{
    int res = 1;
    for (size_t i = 1; i <= n; i++)
    {
        res *= 2;
    }
    return res;
}
int binaryTodecimal(int power)
{
    int result = 0, r;
    temp = head;
    power = power - 1;
    while (temp != 0)
    {
        r = temp->data * powerOfll(power);
        result = result + r;
        temp = temp->next;
        power--;
    }
    return result;
}
int main()
{
    int n, i, decimal;
    printf("how many number you want to enter:");
    scanf("%d", &n);
    create(n);
    display();
    i = lengthOflist1();
    decimal = binaryTodecimal(i);
    printf("the given list in deciamal is: %d", decimal);
    return 0;
}