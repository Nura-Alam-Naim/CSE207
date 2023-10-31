//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll n;
struct node
{
    ll val;
    struct node *next;
} *head = NULL, *tail = NULL, *temp = NULL, *temp1 = NULL,*temp2=NULL;
void create(ll n)
{
    for (int i = 0; i < n;i++){
        ll c;
        cin >> c;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = c;
        temp->next = null;
        if(head==null){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
}
void print()
{
    temp = head;
    while(temp != null){
        cout << temp -> val <<" ";
        temp = temp->next;
    }
    cout << nl;
}
void place_front(ll num)
{
    n++;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val=num;
    if(head==null){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}
void place_back(ll num)
{
    n++;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = num;
    temp->next = null;
    if(head==null){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
void place_at(ll pos, ll num)
{
    n++;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = num;
    if(head==null)
        cout << "No such index exists";
    else{
        temp = head;
        for (int i = 0; i < pos - 1; i++){
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = new_node;
        new_node->next = temp;
    }
    
}
void pop_front()
{
    n--;
    temp = head;
    head = head->next;
    free(temp);
}
void pop_back()
{
    n--;
    temp = head;
    while(temp->next!=null)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = null;
    free(temp);
}
void delete_pos(ll pos)
{
    n--;
    temp = head;
    if (pos == 1)
    {
        head = temp->next;
        free(temp);
    }
    else if (pos == 2)
    {
        head->next = temp->next->next;
        free(temp->next);
    }
    else
    {
        for (ll i = 1; i < pos - 1; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        free(temp);
    }
}
void delete_val(ll num)
{
    n--;
    temp = head;
    while(temp->val!=num && temp->next!=null)
    {
        temp1 = temp;
        temp = temp->next;
    }
    if(temp->val==num)
    {
        temp1->next = temp->next;
        free(temp);
    }
    else
        cout << "Number not found";
}
void sort()
{
    temp = head;
    while (temp != NULL)
    {
        temp1 = temp->next;
        while (temp1 != null)
        {
            if (temp->val < temp1->val)
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

void set_()
{
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    create(n);
    print();
    cout << 1 << nl;
    place_back(99);
    print();
    cout << 2 << nl;
    place_front(99);
    print();
    cout << 3 << nl;
    place_back(99);
    print();
    cout << 4 << nl;
    place_at(3, 99);
    print();
    cout << 5 << nl;
    pop_front();
    print();
    cout << 6 << nl;
    pop_back();
    print();
    cout << 7 << nl;
    delete_pos(3);
    print();
    cout << 8 << nl;
    delete_val(5);
    print();
    cout << 9 << nl;
    sort();
    print();
    cout << 10 << nl;
    set_();
    print();
    cout << 11 << nl;
}