//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll top = -1;
ll n;
void print(ll *st)
{
    cout << nl;
    cout << "Stack looks like: " << nl;
    for (ll i = top; i >= 0;i--)
        cout << st[i] << nl;
    cout << nl;
}
void push(ll *st)
{
    if (top >= n)
    {
        cout << "Stack Overload" << nl;
        return;
    }
    ll val;
    cout << "Enter value: ";
    cin >> val;
    top++;
    st[top] = val;
    print(st);
}
void pop(ll *st)
{
    if (top ==-1)
    {
        cout << "Stack is empty" << nl;
        return;
    }
    st[top] = 0;
    top--;
    print(st);
}
void printst(ll *st)
{
    cout << nl;
    cout << "Stack looks like: " << nl;
    for (ll i = top; i >= 0; i--)
        cout << st[i] << " ";
    cout << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Enter size of stack: ";
    cin >> n;
    ll st[n];
    while (true)
    {
        cout << "1. Push value to stack "<<nl;
        cout << "2. Pop value from stack " << nl;
        cout << "3. Print value taken from stack " << nl;
        cout << "4. Exit" << nl;
        cout << "Enter choice: ";
        ll choice;
        cin >> choice;
        if(choice==1)
            push(st);
        else if(choice==2)
            pop(st);
        else if(choice==3)
            printst(st);
        else
            break;
    }
}