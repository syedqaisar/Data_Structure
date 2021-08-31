
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, num;
    printf("how many number yoou want in array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        
    }
    printf("the orignal array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    return 0;
}
