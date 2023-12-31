//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll *arr = null;
ll *cpy = null;
ll len = 0;
ll pos = 0;
ll f = -1, r = -1, cnt=0;
void clear()
{
    len = 0;
    pos = 0;
    f = -1;
    r = -1;
    delete[] arr;
    delete[] cpy;
}
void print(ll *main)
{
    
    cout << nl;
    for (ll i = 0; i < cnt;i++)
        cout << main[i] << " ";
    cout << nl;
}
void enqueue(ll n)
{
    if (cnt == len)
    {
        cout << "Queue is full" << nl;
        return;
    }
    else if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        arr[r] = n;
        cnt++;
    }
    else
    {
        r = (r + 1) % len;
        arr[r] = n;
        cnt++;
    }
}

ll dequeue()
{
    ll rtn = 0;
    if (f == -1 && r == -1)
    {
        cout << "Queue is empty" << nl;
        return rtn;
    }
    else if(r==f)
    {
        rtn= arr[f];
        f = -1;
        r = -1;
        cnt = 0;
        return rtn;
    }
    else
    {
        rtn = arr[f];
        f = (f + 1) % len;
        cnt--;
        return rtn;
    }
}
int main()
{
    while (true)
    {
        cout << nl;
        cout << "###### MENU ######" << nl;
        cout << "1. Creat Queue" << nl;
        cout << "2. Enqueue Value" << nl;
        cout << "3. Dequeue value" << nl;
        cout << "4. Print queue" << nl;
        cout << "5. Copy queue" << nl;
        cout << "Enter Choice: ";
        ll c;
        cin >> c;
        if (c == 1)
        {
            clear();
            cout << "Enter size of queue: ";
            cin >> len;
            arr = (ll *)malloc(len*sizeof(ll));
            cout << nl;
        }
        else if (c == 2)
        {
            cout << "Enter value: ";
            ll val;
            cin >> val;
            enqueue(val);
            print(arr);
        }
        else if (c == 3)
        {
            ll val = dequeue();
            if (val)
                cout << val << nl;
        }
        else if (c == 4)
        {
            print(arr);
        }
        else if (c == 5)
        {
            cpy =(ll *)malloc(cnt*sizeof(ll));
            ll crnt = 0;
            while (crnt < cnt)
            {
                ll c = dequeue();
                enqueue(c);
                cpy[crnt] = c;
                crnt++;
            }
            cout << "Real Queue: ";
            print(arr);
            cout << "Copied Queue: ";
            print(cpy);
        }
    }
}