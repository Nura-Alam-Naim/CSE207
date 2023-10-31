//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct NODE{
    int data;
    struct NODE *pre=null,*next;
}node, *head=NULL,*temp=NULL,*tail=NULL,*temp1=NULL,*temp2=NULL;
void print()
{
    cout << "VALUES:  ";
    temp = head;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}
void create(){
    ll n;
    cout << "#Enter size: ";
    cin >> n;
    cout << "Enter values: ";
    while(n--)
    {
        temp = (struct NODE *)malloc(sizeof(struct NODE));
        temp->next = null;
        
        cin >> temp->data;
        if (head == null)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->pre = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    print();
}
void place_front()
{
    temp = (struct NODE *)malloc(sizeof(struct NODE));
    cout << "#Enter value: ";
    cin >> temp->data;
    if(head == null )
    {
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    print();
}
void place_back()
{
    temp = (struct NODE *)malloc(sizeof(struct NODE));
    cout<<"#Enter the value: ";
    cin>>temp->data;
    temp->next = null;
    if (head == null)
    {
        head = temp;
        tail = temp;
    }
    else{
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
    }
    print();
}
void place_at()
{
    cout << "#Enter position: ";
    ll pos;
    cin >> pos;
    cout << "Enter the value: ";
    struct NODE* node = (struct NODE *)malloc(sizeof(struct NODE));
    cin >> node->data;
    if (head == null)
        cout << "#No such index exists";
    else if(pos==1)
    {
        node->next = head;
        head->pre = node;
        head = node;
    }
    else
    {
        temp = head;
        ll len = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        if (pos > len)
        {
            cout << "#No such index exists" << nl;
            return;
        }
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = node;
        node->pre = temp1;
        node->next = temp;
        temp->pre = node;
    }
    print();
}
void pop_bck()
{
    cout << "#Deleting last value: " << nl;
    temp = tail;
    tail = temp->pre;
    tail->next=null;
    free(temp);
    print();
}
void pop_frnt()
{
    cout << "#Deleting first value: " << nl;
    temp = head;
    head = head->next;
    head->pre = null;
    free(temp);
    print();
}
void delete_pos()
{
    ll pos;
    cout << nl << "#Deleting position " << nl;
    cout << "Enter position: ";
    cin >> pos;
    cout << nl;
    temp = head;
    if (pos == 1)
    {
        head = temp->next;
        head->pre = null;
        free(temp);
    }
    else if (pos == 2)
    {
        temp = head->next;
        head->next = temp->next;
        temp->next->pre = head;
        free(temp);
    }
    else if (pos > 2)
    {
        ll len = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        if (pos > len)
        {
            cout << "#No such index exists" << nl;
            return;
        }
        temp = head;
        for (ll i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        temp->next->pre = temp1;
        free(temp);
    }
    else
        cout << "#No such index exists" << nl;
    print();
}
void reverse()
{
    cout << nl << "#Reversing all elements." << nl;
    temp = head;
    while(temp!=null)
    {
        temp1 = temp->next;
        temp->next = temp->pre;
        temp->pre = temp1;
        temp = temp1;
    }
    temp2 = head;
    head = tail;
    tail = temp;
    print();
}
void distinct()
{
    cout << "Removing duplicate values: " << nl;
    temp = head;
    while (temp != null)
    {
        ll tval = temp->data;
        temp2 = temp->next;
        temp1 = temp;
        while (temp2 != null)
        {
            if (temp2->data == tval)
            {
                temp1->next = temp2->next;
                free(temp2);
            }
            else
                temp1 = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    print();
}
int main()
{
    cout << "# Creating Linked List: " << nl;
    create();
    while (true)
    {
        cout << nl;
        cout << "1.Insert a new node" << nl;
        cout << "2.Insert node at beginning" << nl;
        cout << "3.Insert node at any position" << nl;
        ll choice;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
            place_back();
        else if (choice == 2)
            place_front();
        else if (choice == 3)
            place_at();
        else
            break;
    }
    string inp;
    pop_bck();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    getline(cin, inp);
    pop_frnt();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    delete_pos();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    getline(cin, inp);
    reverse();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    distinct();
}