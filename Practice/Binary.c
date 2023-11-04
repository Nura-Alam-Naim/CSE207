#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *top = (struct node *)(sizeof(struct node));
void print()
{
    printf("\nBinary Number: ");
    struct node *temp = (struct node *)(sizeof(struct node));
    temp = top;
    while (temp != NULL)
    {
        int number = temp->value;
        printf("%d",number );
        temp = temp->next;
    }
    printf("\n");
}
void push(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = x;
    temp->next = NULL;
    if (top == NULL)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    while (n > 0)
    {
        int m = n % 2;
        push(m);
        n /= 2;
    }
    print();
}