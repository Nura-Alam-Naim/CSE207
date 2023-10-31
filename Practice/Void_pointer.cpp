//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
typedef long long ll;
#define nl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    void *p;
    int i = 7;
    float f = 23.5;
    p = &i;
    cout << "i contains value: " << *((int *)p)<<nl;
    p = &f;
    cout <<fixed<<setprecision(9)<< "f contails value: " << *((float *)p) << nl;
}