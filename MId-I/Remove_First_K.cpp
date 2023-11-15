//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll qlen = 0, qpos = 0;
struct node
{
    int data;
    struct node *next=null;
};
node *head = null, *tail = null,*temp=null,*temp1=null;
void enqueue(ll num)
{
    if (qpos >= qlen)
    {
        cout << "Queue is full" << nl;
        return;
    }
    qpos++;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    if (head == null)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
ll dequeue()
{
    if (!qpos)
        return -1;
    qpos--;
    temp = head;
    ll ret = temp->data;
    head = head->next;
    free(temp);
    return ret;
}
void display()
{
    temp = head;
    while(temp!=null)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << nl;
}
int top = -1;
int *stck;
void push(ll x)
{
    if(top+1==qlen)
    {
        cout << "Stack is full" << nl;
        return;
    }
    top++;
    stck[top] = x;
}
int pop()
{
    if(top==-1)
        return -1;
    int ret = stck[top];
    top--;
    return ret;
}
void first_k(ll n)
{
    ll cnt = 0;
    while(cnt!=n)
    {
        //cout << cnt << " ";
        cnt++;
        push(dequeue());
    }
    while(top!=-1)
        enqueue(pop());
}
int main()
{
    qlen = 10;
    stck = (int *)malloc(qlen * sizeof(int));
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    display();
    first_k(10);
    display();
}