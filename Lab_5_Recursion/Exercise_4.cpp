//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll temp = 0;
ll palindrom(ll n)
{
    if(!n)
        return temp;
    temp = (temp * 10) + (n % 10);
    return palindrom(n / 10);
}
int main()
{
    cout << "Enter a number: ";
    ll num;
    cin >> num;
    if(num==palindrom(num))
        cout << "Number is palindromic" << nl;
    else
        cout << "Number is not palindromic" << nl;
}