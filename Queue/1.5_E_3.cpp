#include <bits/stdc++.h>
using namespace std;
#define size 100
class queu
{
    int f;
    int r;
    int q[size];
    int cnt;

public:
    void init();
    void enqueue(int x);
    int dequeue();
    int len();
};
void queu::init()
{
    f = -1;
    r = -1;
    cnt = 0;
}
int queu::len()
{
    return r + 1;
}
void queu::enqueue(int x)
{
    if (r == cnt)
    {
        cout << "Stack is full\n";
        return;
    }
    else if (f == -1 && r == -1)
    {
        f++;
        r++;
    }
    else
        r = (r + 1) % size;
    q[r] = x;
    cnt++;
}
int queu:: dequeue()
{
    int rtn = 0;
    if(f==-1 && r==-1)
    {
        cout << "Queue is empty\n";
        return rtn;
    }   
    else if(f==r)
    {
        rtn = q[f];
        f = -1;
        r = -1;
        cnt = 0;
        return rtn;
    }
    else
    {
        rtn=q[f];
        cnt--;
        f = (f + 1) % size;
        return rtn;
    }
}
int main()
{
    queu q1, q2;
    q1.init();
    q2.init();
    for (int i = 0; i < 5; ++i)
    {
        q1.enqueue(i + 1);
        q2.enqueue(1 << i);
    }
    int l1 = q1.len();
    int l2 = q2.len();
    for (int i = 0; i < 5; ++i)
    {
        // q1.enqueue(i + 1);
        // q2.enqueue(1 << i);
        cout << "Q1: " << q1.dequeue() << '\n';
        cout << "Q2: " << q2.dequeue() << "\n";
    }
}
