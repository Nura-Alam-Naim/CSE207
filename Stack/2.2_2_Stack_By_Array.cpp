//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
class stack{
    int top;
    int *arr; // arr[];
    int size;
    public:
    stack(int s){
        arr = (int *)malloc(s * sizeof(int)); // arr[s];
        top = -1;
        size = s;
    }
    bool isFull()
    {
        return top + 1 >= size ? true : false;
    }
    void push(int x)
    {
        if(!isFull())
        {
            top++;
            arr[top] = x;
        }
        else
            cout << "Stack Overflow"<<nl;
    }
    bool empty(){
        return top == -1 ? true : false ;
    }
    int pop()
    {
        int ret = 0;
        if (!empty())
        {
            ret = arr[top];
            top--;
        }
        else
            cout << "Stack Empty" << nl;
        return ret;
    }
    
};
int main()
{
    :: stack s(5);
    int i = 1;
    while(!s.isFull()) 
    {
        s.push(i * i);
        i++;
    }
    while(!s.empty())
    {
        cout << s.pop()<<nl;
    }
}