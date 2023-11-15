//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL, *temp1 = NULL;
void push(int n)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = n;

    if (head == NULL)
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
void middle_List()
{
    int cnt = 0;
    temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp1 = temp;
        temp = temp->next;
    }
    ll c = 0;
    temp = head;
    while (temp != null)
    {
        c++;
        if (c == ((cnt / 2) + 1))
        {
            cout << temp->data << nl;
            return;
        }
        temp1 = temp;
        temp = temp->next;
    }
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << nl;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    middle_List();
    
    
}