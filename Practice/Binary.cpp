//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll stackSize = 0;
ll pushed_into = 0;
struct node
{
    int data;
    struct node *next;
};
struct node *top = (struct node *)(sizeof(struct node));
void print()
{
    cout << nl << "Binary Number: ";
    struct node *temp = (struct node *)(sizeof(struct node));
    temp = top;
    while (temp != null)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << nl;
}
void push(int x)
{
    pushed_into++;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = null;
    if (top == null)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    stackSize = num;
    while (num>0)
    {
        int n = num % 2;
        push(n);
        num /= 2;
    }
    print();
}