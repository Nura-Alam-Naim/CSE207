//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    ll val;
    struct node *next = null;
} *head = NULL, *tail = NULL, *temp = NULL;
void print()
{
    cout << nl << "VALUES: ";
    temp = head;
    while (temp != null)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << nl;
}
struct node* reverse(struct node *node)
{
    if (node == null)
        return null;
    if (node->next == null)
    {
        head = node;
        return node;
    }
    temp = reverse(node->next);
    temp->next = node;
    node->next = null;
    return node;
}
void push(ll n)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = n;
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
int main()
{
    ll n;
    cout << "Enter size of list: ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        cout << "Enter value"<< "(" << i << "): ";
        ll c;
        cin >> c;
        push(c);
        i++;
    }
    print();
    reverse(head);
    cout << "Reversed list: ";
    print();
}