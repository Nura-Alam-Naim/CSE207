//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    int data;
    struct node *next, *previous;
};
node *head = null, *tail = null;
void push(int x)
{
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = null;
    temp->previous = null;
    if (head == null)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
}
void display()
{
    node *temp = head;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}
void delete_Duplicate(int number)
{
    node *temp;
    while(head->data==number)
    {
        temp = head;
        head->next->previous = null;
        head=head->next;
        free(temp);
    }
    node *temp1 = head;
    temp = head->next;
    node *temp3;
    while(temp!=null)
    {
        if(temp->data==number)
        {
            temp3 = temp;
            temp->previous = temp1;
            temp1->next = temp->next;
            free(temp3);
            
        }
        temp1 = temp;
        temp = temp->next;
    }
}
int main()
{
    push(2);
    push(2);
    push(10);
    push(8);
    push(4);
    push(2);
    push(5);
    push(6);
    display();
    delete_Duplicate(2);
    display();
}