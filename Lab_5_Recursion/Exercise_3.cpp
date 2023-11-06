//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll gcd(ll n1, ll n2)
{
    if (!n2)
        return n1;
    return gcd(n2, n1 % n2);
}
int main()
{
    ll n1, n2;
    cout << "Input first number: ";
    cin >> n1;
    cout << "Input second number: ";
    cin >> n2;
    cout << "LCM: " << (n1*n2)/gcd(n1, n2);
}