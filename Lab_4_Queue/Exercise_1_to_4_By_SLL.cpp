//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll len;
ll pos = 0;
struct node{
    ll data;
    struct node *next = null;
} *head=null, *tail=null, *temp=null, *cpy_head=null,*cpy_tail=null,*temp1=null;
void clear()
{
    while(head!=null)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    len = 0;
    pos = 0;
}
void print(struct node *main)
{
    temp = main;
    while(temp!=null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}
void enqueue(ll num)
{
    if(pos>=len)
    {
        cout << "Queue is full" << nl;
        return;
    }
    pos++;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
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
    if(!pos)
        return 0;
    pos--;
    temp = head;
    ll ret = temp->data;
    head = head->next;
    free(temp);
    return ret;
}
int main()
{
    while(true)
    {
        cout << nl;
        cout << "###### MENU ######" << nl;
        cout << "1. Creat Queue" << nl;
        cout << "2. Enqueue Value" << nl;
        cout << "3. Dequeue value" << nl;
        cout << "4. Print queue" << nl;
        cout << "5. Copy queue" << nl;
        cout << "Enter Choice: ";
        ll c;
        cin >> c;
        if(c==1)
        {
            clear();
            cout << "Enter size of queue: ";
            cin >> len;
            cout << nl;
        }
        else if(c==2)
        {
            cout << "Enter value: ";
            ll val;
            cin >> val;
            enqueue(val);
        }
        else if(c==3)
        {
            ll val = dequeue();
            if(!val)
                cout << "Queue is empty" << nl;
            else
                cout << val<<nl;
        }
        else if(c==4)
        {
            print(head);
        }
        else if(c==5)
        {
            ll crnt = 0;
            while(crnt!=pos)
            {
                ll val = dequeue();
                enqueue(val);
                temp1 = (struct node *)malloc(sizeof(struct node));
                temp1->data = val;
                if(cpy_head==null)
                {
                    cpy_head = temp1;
                    cpy_tail = temp1;
                }
                else{
                    cpy_tail->next = temp1;
                    cpy_tail = temp1;
                }
                crnt++;
            }
            cout << "Real Queue: ";
            print(head);
            cout << "Copied Queue: ";
            print(cpy_head);
        }
    }
}