//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll siz = 0;
ll top = -1;
char *stck;
void push(char x) { 
    if(top+1==siz)
    {
        cout << "Stack is full" << nl;
        return;
    }
    top++;
    stck[top] = x;
}
char pop()
{
    if(top==-1)
        return '\0';
    char ret = stck[top];
    top--;
    return ret;
}
void  reve(char *str)
{
    char next;
    for (int i = 0; i < siz;i++)
    {
        if(str[i]==' ')
        {
            i++;
            while((next=pop())!='\0')
                cout << next;
            cout << ' ' ;
        }
        push(str[i]);
    }
    while ((next = pop()) != '\0')
        cout << next;
}
int main()
{
    char str[100];
    cin.getline(str, 100);
    cout << str << nl;
    siz = strlen(str);
    stck = (char *)malloc(siz * sizeof(char));
    reve(str);
}