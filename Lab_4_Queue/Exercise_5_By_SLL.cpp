//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll len;
ll pos = 0;
char str[100];
struct node
{
    char data;
    struct node *next = null;
} *head = null, *tail = null, *temp = null;
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
    while (temp != null)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << nl;
}
void enqueue(char ch)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ch;
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
char dequeue()
{
    temp = head;
    ll ret = temp->data;
    head = head->next;
    free(temp);
    return ret;
}
int main()
{
    cout << "Enter String: ";
    cin.getline(str,100);
    len = strlen(str);
    for (int i = 0; i < len; i++)
        enqueue(str[i]);
    while (pos!= len)
    {
        char c = dequeue();
        if (c != ' ')
            enqueue(c);
        pos++;
    }
    print(head);
}