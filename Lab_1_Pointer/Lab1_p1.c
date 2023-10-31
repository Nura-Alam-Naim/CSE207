//|ADMIRAL AUDITORE|//
#include<stdio.h>
#include<stdlib.h>
int* max(int *p,int *q)
{
    int *max;
    max = (int *)malloc(1 * sizeof(int));
    *max = -1;
    for (int i = 0; i < *q; i++)
        if(*(p+i)>*max)
            max = (p + i);
    return max;
}
int main()
{
    int *q = NULL;
    q = (int *)malloc(1 * sizeof(int));
    scanf("%d", q);
    int i, *p = NULL;
    p = (int *)malloc(*q * sizeof(int));
    for (int i = 0; i < *q;i++)
        scanf("%d", (p + i));
    printf("Maximum value: %d", *max(p, q));
}