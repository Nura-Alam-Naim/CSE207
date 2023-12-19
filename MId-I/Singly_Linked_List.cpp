//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node{
    int data;
    struct node* next;
} *head = null, *tail = null, *temp = null, *temp1 = null, *temp2=null, *nde = null;
void print()
{
    temp = head;
    while(temp!=null)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << nl;
}
void insert_back(int val) {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    if(!head)
    {
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
void insert_front(int val)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=head;
    if(!tail)
        tail = temp;
    head = temp;
}
void insert_at(int val, int pos)
{
    if(pos==1)
    {
        insert_front(val);
        return;
    }
        
    ll cnt = 2;
    temp1 = head;
    temp = head->next;
    while(cnt<=pos&&temp1!=null)
    {
        if(cnt==pos)
        {
            nde = (struct node *)malloc(sizeof(struct node));
            nde->data = val;
            nde->next = temp;
            temp1->next = nde;
            return;
        }
        cnt++;
        temp1 = temp;
        temp = temp->next;
    }
    cout << "No Such Index/Value Exists" << nl;
}
void delete_front()
{
    temp = head;
    head = head->next;
    free(temp);
}
void delete_last()
{
    temp = head;
    while(temp->next!=null)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = null;
    tail = temp1;
    free(temp);
}
void delete_at(int pos)
{
    if(pos==1)
    {
        delete_front();
        return;
    }
    temp1 = head;
    temp = head->next;
    ll cnt = 2;
    while(cnt<=pos&&temp1!=null)
    {
        if(cnt==pos)
        {
            temp1->next = temp->next;
            free(temp);
            return;
        }
        cnt++;
        temp1 = temp;
        temp = temp->next;
    }
    cout << "No such Index/Value Exists" << nl;
}
int search(int val)
{
    ll pos = 1;
    temp = head;
    while(temp!=null)
    {
        if(temp->data==val)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}
void delete_val(int val)
{
    delete_at(search(val));
}
void sort()
{
    temp = head;
    ll cnt = 0;
    while(temp!=null)
    {
        temp1 = temp->next;
        while(temp1!=null)
        {
            if(temp->data>temp1->data)
            {
                nde = temp1->next;
                temp1->next = temp;
                temp->next = nde;
                
            }
            if (!cnt)
                head = temp1;
            temp1 = temp1->next;
        }
        cnt = 1;
        temp2 = temp;
        temp = temp->next;
    }
    tail = temp2;
}
void disticnt()
{
    temp = head;
    while(temp!=null)
    {
        int tval = temp->data;
        temp2 = temp->next;
        temp1 = temp;
        while(temp2!=null)
        {
            if(temp2->data ==tval)
            {
                temp1->next = temp2->next;
                free(temp2);
            }
            else
                temp1 = temp2;
            temp2 = temp2->next;
        }
        nde = temp;
        temp = temp->next;
    }
    tail = nde;
}
void reverse()
{
    temp = head;
    tail = head;
    while(temp!=null)
    {
        temp1 = temp->next;
        temp->next = temp2;
        temp2 = temp;
        temp = temp1;
    }
    head = temp2;
}

int main()
{
    insert_back(10);
    insert_back(5);
    insert_back(100);
    insert_back(10);
    insert_back(5);
    insert_back(100);
    print();
    sort();
    print();
    disticnt();
    print();
}