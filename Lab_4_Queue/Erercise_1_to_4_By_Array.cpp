//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll *arr = null;
ll len = 0;
ll pos = 0;
ll f = -1, r = -1, cnt=0;
void clear()
{
    len = 0;
    pos = 0;
    f = -1;
    r = -1;
}
void enqueue(ll n)
{
    if(cnt==len)
    {
        cout << "Queue if full" << nl;
        return;
    }
    else if(f==-1 && r==-1)
    {
        f++;
        r++;
    }
    else
        r = (r + 1) % len;
    arr[r] = n;
    cnt++;
}
ll dequeue()
{
    ll rtn = -1;
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
    }
    else
    {
        rtn = arr[f];
        f = (f + 1) % len;
    }
    cnt--;
    return rtn;
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
            ll a[len];
            arr = &a[0];
            cout << nl;
        }
        else if (c == 2)
        {
            cout << "Enter value: ";
            ll val;
            cin >> val;
            enqueue(val);
        }
        else if (c == 3)
        {
            ll val = dequeue();
            if (!val)
                cout << "Queue is empty" << nl;
            else
                cout << val << nl;
        }
        else if (c == 4)
        {
            print(head);
        }
        else if (c == 5)
        {
            ll crnt = 0;
            while (crnt != pos)
            {
                ll val = dequeue();
                enqueue(val);
                temp1 = (struct node *)malloc(sizeof(struct node));
                temp1->data = val;
                if (cpy_head == null)
                {
                    cpy_head = temp1;
                    cpy_tail = temp1;
                }
                else
                {
                    cpy_tail->next = temp1;
                    cpy_tail = temp1;
                }
                crnt++;
            }
            cout << "Real Queue: ";
            print(head);
            cout << "Copied Queue: ";
            print(cpy_head);
        }
    }
}