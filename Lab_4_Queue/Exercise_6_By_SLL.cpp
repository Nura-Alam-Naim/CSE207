//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll len=0;
ll pos = 0;
struct node
{
    ll data;
    struct node *next = null;
} *head = null, *tail = null, *temp = null, *top=null, *temp1 = null;
void print(struct node *main)
{
    temp = main;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}
void push(ll n)
{
    len++;
    temp1 = (struct node *)malloc(sizeof(struct node));
    temp1->data = n;
    if(top==null)
        top = temp1;
    else{
        temp1->next = top;
        top = temp1;
    }
}
ll pop()
{
    ll rtn = top->data;
    temp1 = top;
    top = top->next;
    free(temp1);
    return rtn;
}
void enqueue(ll n)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    if(head==null)
    {
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
ll dequeue()
{
    ll rtn = head->data;
    temp = head;
    head = head->next;
    free(temp);
    return rtn;
}
int main()
{
    cout << "S: ";
    ll s;
    while(cin>>s)
        push(s);
    pos = len;
    while(len--)
        enqueue(pop());
    cout << "Q: ";
    while(pos--)
        cout << dequeue() << " ";
}