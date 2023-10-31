#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a, b, *p=NULL, *q=NULL;
    a = 10;
    b = 100;
    p = &a;
    q = &b;
    printf("a = %d, b = %d \n", a, b);
    swap(p, q);
    printf("a = %d, b = %d \n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d \n", a, b);
}