//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll len = 0;
ll pos = 0;
struct node{
    ll data;
    struct node *next = null;
} *head = null, *tail = null, *temp = null;
void enqueue(ll num)
{
    len++;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    if(head==null)
    {
        head = temp;
        tail = temp;
    }
    else{
        tail->next=temp;
        tail = temp;
    }
}
ll dequeue()
{
    ll ret = head->data;
    temp = head;
    head = head->next;
    free(temp);
    return ret;
}
void print()
{
    temp = head;
    while(temp!=null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}
int main()
{
    ll s;
    cout << "Q: ";
    while(cin>>s)
        enqueue(s);
    pos = len;
    cout << nl << "Q: ";
    while(pos--)
    {
        ll c = dequeue();
        if(c>=0)
            enqueue(c);
    }
    print();
}