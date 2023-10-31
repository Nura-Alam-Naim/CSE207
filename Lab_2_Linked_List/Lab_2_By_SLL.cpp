#include<bits/stdc++.h>
//#include<conio.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    ll val;
    struct node *next;
} *head = NULL, *tail = NULL, *temp = NULL, *temp1 = NULL,*temp2=NULL,*tempval=NULL;
void print()
{
    cout << nl << "VALUES: ";
    temp = head;
    while(temp != null)
    {
        cout << temp -> val <<" ";
        temp = temp->next;
    }
    cout << nl;
    // int input;
    // cout << "Press Enter to Continue: ";
    // input = getch();
    // if(input==13)
    //     system("cls");
}
void create(ll n)
{
    cout<<"Enter values: ";
    for (int i = 0; i < n; i++)
    {
        ll c;
        cin >> c;
        temp = (struct node *)malloc(sizeof(struct node));
        cin >> temp->val;
        temp->next = null;
        if(head==null)
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
    print();
}
void place_front()
{
    ll num;
    cout<<"Enter Value: ";
    cin>>num;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val=num;
    if(head==null)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    print();
}
void place_back()
{
    ll num;
    cout<<"Enter Value: ";
    cin>>num;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = num;
    temp->next = null;
    if(head==null)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    print();
}
void place_at()
{
    ll pos;
    cout<<"Enter position: ";
    cin>>pos;
    ll num;
    cout<<"Enter Value: ";
    cin>>num;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = num;

    if(head==null)
        cout << "No such index exists";
    else if(pos==1)
    {
        new_node->next = head;
        head = new_node;
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
            cout << "No such index exists" << nl;
            return;
        }
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = new_node;
        new_node->next = temp;
    }
    print();
}
void delete_front()
{
    cout<<nl<<"Deleting first node"<<nl;
    temp = head;
    head = head->next;
    free(temp);
    print();
}
void delete_back()
{
    cout<<nl<<"Deleting last node"<<nl;
    temp = head;
    while(temp->next!=null)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = null;
    free(temp);
    print();
}
void delete_pos()
{
    ll pos;
    cout << nl << "Deleting position " << nl;
    cout << "Enter position: ";
    cin >> pos;
    cout << nl;

    temp = head;
    if (pos == 1)
    {
        head = temp->next;
        free(temp);
    }
    else if (pos == 2)
    {
        temp = head->next;
        head->next = temp->next;
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
        if (pos > len )
        {
            cout << "No such index exists" << nl;
            return;
        }
        temp = head;
        for (ll i = 1; i < pos - 1; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        free(temp);
    }
    else
    {
        cout << "No such index exists" << nl;
    }
    print();
}
void sort()
{
    temp = head;
    while (temp != NULL)
    {
        temp1 = temp->next;
        while (temp1 != null)
        {
            if (temp->val > temp1->val)
            {
                ll o = temp->val;
                temp->val = temp1->val;
                temp1->val = o;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}
void distinct()
{
    cout << "Removing duplicate values: " << nl;
    temp = head;
    while (temp != null)
    {
        ll tval = temp->val;
        temp2 = temp->next;
        temp1 = temp;
        while (temp2 != null)
        {
            if (temp2->val == tval)
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

void reverse()
{
    cout <<nl<< "Reversing all elements."<<nl;
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
    print();
}
int main()
{
    ll n;
    cout << "Creating Linked List: " << nl;
    cout<<"Enter size: ";
    cin>>n;
    create(n);
    while(true)
    {
        //system("cls");
        cout<<nl;
        cout<<"1.Insert a new node"<<nl;
        cout<<"2.Insert node at beginning"<<nl;
        cout<<"3.Insert node at any position"<<nl;
        ll choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1)
            place_back();
        else if(choice==2)
            place_front();
        else if(choice==3)
            place_at();
        else
            break;
    }

    cout << nl;
    string inp;
    delete_front();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    getline(cin,inp);
    cout << nl;
    delete_back();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    cout << nl;
    delete_pos();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    cout << nl;
    distinct();
    cout << "Press Enter to Continue: ";
    getline(cin, inp);
    cout << nl;
    reverse();
}
