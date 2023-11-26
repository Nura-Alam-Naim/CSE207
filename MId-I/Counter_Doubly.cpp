//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node{
    int data;
    struct node *next, *previous;
};
node *head=null, *tail=null,*temp,*temp1;
void push(int x)
{
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next = null;
    temp->previous = null;
    if(head==null)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
}
void anti_clock(int n)
{
    // for (int i = 0; i < n;i++)
    // {
    //     struct node *temp = head;
    //     head = head->next;
    //     head->previous = null;
    //     tail->next = temp;
    //     temp->previous = tail;
    //     tail = temp;
    //     tail->next = null;
    // }
    // n++;
    temp=head;
    temp1 = null;
    while(n--)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = null;
    temp->previous = null;

    tail->next = head;
    head->previous = tail;
    tail = temp1;
    head = temp;
}
void display()
{
    node *temp = head;
    while(temp!=null)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << nl;
}
int main()
{
    push(10);
    push(15);
    push(12);
    push(13);
    push(20);
    push(14);
    display();
    anti_clock(4);
    display();
}