#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr;
    printf("how many number yoou want in array:");
    scanf("%d", &n);
    int a[n];
    ptr = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }
    printf("the orignal array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", *(ptr + i));
    }
    printf("the orignal array using array[size] is: \n");
    for (i = 0; i < n; i++)
    {
        a[i] = *(ptr + i);
        printf("%d, ", a[i]);
    }

    return 0;
}
