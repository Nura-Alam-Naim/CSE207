//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node{
    ll data;
    struct node *next=null;
} *top = null, *temp = null;
ll s;
ll len = -1;
void print()
{
    cout << nl;
    cout << "Stack looks like: " << nl;
    temp = top;
    while(temp!=null){
        cout << temp->data << nl;
        temp = temp->next;
    }
    cout << nl;
}
void push()
{
    if(len>=s)
    {
        cout << "Stack Overload" << nl;
        return;
    }
    len++;
    ll val;
    cin >> val;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    if(top==null)
        top = temp; 
    else{
        temp->next = top;
        top = temp;
    }
}
void pop() 
{
    if(len==-1)
    {
        cout << "Stack empty" << nl;
        return;
    }
    len--;
    temp = top;
    top = temp->next;
    free(temp);
}
void printst()
{
    temp = top;
    while (temp != null)
    {
        cout << temp->data << nl;
        temp = temp->next;
    }
    cout << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Enter size of stack: ";
    cin >> s;
    while (true)
    {
        cout << "1. Push value to stack " << nl;
        cout << "2. Pop value from stack " << nl;
        cout << "3. Print value taken from stack " << nl;
        cout << "4. Exit" << nl;
        cout << "Enter choice: ";
        ll choice;
        cin >> choice;
        if (choice == 1)
            push();
        else if (choice == 2)
            pop();
        else if (choice == 3)
            printst();
        else
            break;
    }
}