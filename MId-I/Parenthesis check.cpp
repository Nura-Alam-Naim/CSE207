//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
int siz = 0;
int len = 0;

struct node
{
    char data;
    struct node *next=null;
};
struct node *top = NULL;
void push(char n)
{
    if(len==siz)
    {
        cout << "Stack is full" << nl;
        return;
    }
    len++;
    struct node *temp = (node *)malloc(sizeof(node));
    temp->data = n;
    if(top==null)
        top = temp;
    else{
        temp -> next = top;
        top = temp;
    }
}
char pop()
{
    if(len==0)
        return '\0';
    char ch = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    len--;
    return ch;
}
bool empty()
{
    return len > 0;
}
bool check(string str)
{
    siz = str.length();
    for(int i=0;i<siz;i++)
    {
        if(str[i]=='{'||str[i]=='['||str[i]=='(')
            push(str[i]);
        else if(str[i]=='}')
        {
            if(pop()!='{')
                return false;
        }
        else if (str[i] == ']')
        {
            if (pop() != '[')
                return false;
        }
        else if (str[i] == ')')
        {
            if (pop() != '(')
                return false;
        }
    }
    return len==0;
}
int main()
{
    //cout << check("[()]{}{[()()]()}") << nl;
    cout << check("(([()])))");
}