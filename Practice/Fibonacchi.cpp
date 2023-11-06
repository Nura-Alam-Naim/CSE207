//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll fibonacchi(ll n)
{
    if(n==1|| n==0)
        return n;
    return fibonacchi(n - 1) + fibonacchi(n - 2);
}
int main()
{
    ll n;
    cout << "nth fibonacchi. Enter value of n: ";
    cin >> n;
    cout << fibonacchi(n-1);
}