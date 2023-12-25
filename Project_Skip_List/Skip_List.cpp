//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    int data;
    struct node *next = null;
    struct node *previous = null;
    struct node *up = null;
    struct node *down = null;
};
struct node *head = (struct node *)malloc(sizeof(struct node));
struct node *tail = (struct node *)malloc(sizeof(struct node));
struct node* search(int val)
{
    struct node *temp = head;
    while(temp->down!=null)
    {
        temp = temp->down;
        while(val>=temp->down->data)
        {
            temp = temp->next;
        }
    }
    return temp;
}

int level = 0;
int main()
{
    head->data = INT_MIN;
    tail->data = INT_MAX;
    head->next = tail;
    tail->previous = head;
}