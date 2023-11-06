//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll power(ll num,ll pow)
{
    if(!pow)
        return 1;
    if(!(pow&1))
        return power(num*num, pow / 2);
    return num * power(num, pow - 1);
}
// ll power(ll n,ll p)
// {
//     if(p<=1)
//         return 1;
//     return n * power(p, n - 1);
// }
int main()
{
    ll num, pow;
    cout << "Input any number: ";
    cin >> num;
    cout << "Inout power: ";
    cin >> pow;
    cout << "Output: " << power(num, pow);
}