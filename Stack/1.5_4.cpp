#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
class stackk{
    char stck[SIZE];
    int top;
    public:
        void push(char ch);
        char pop();
        void init();
        int len();
};

void stackk::init()
{
    top = 0;
}
int stackk::len()
{
    return top;
}
void stackk::push(char ch)
{
    if(top==SIZE) 
    {
        cout << "Stack is full\n";
        return;
    }
    stck[top] = ch;
    top++;
}
char stackk::pop()
{
    if(!top)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    top--;
    return stck[top];
}
int main()
{
    stackk s1,s2;
    s1.init();
    s2.init();
    s1.push('x');
    s1.push('y');
    s1.push('z');
    s2.push('a');
    s2.push('b');
    s2.push('c');
    int sl1 = s1. len();
    int sl2 = s2.len();
    for (int i = 0; i <sl1;i++)
        cout << "Pop s1: " << s1.pop() << " ";
    cout << "\n";
    for (int i = 0; i <sl2;i++)
        cout << "Pop s2: " << s2.pop() << ' ';
}

