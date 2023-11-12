//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
void DeleteDuplicate(int *n, int *p)
{
    for (int i = 0; i < *n;i++)
        for (int j = i + 1; j < *n;j++)
            if(*(p+i)==*(p+j))
            {
                for (int k = j; k < *n-1; k++)
                    *(p + k) = *(p + k + 1);
                (*n)--;
            }
}
int main()
{
    int n;
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    arr[0] = 10;
    arr[1] = 9;
    arr[2] = 10;
    arr[3] = 8;
    arr[4] = 9;
    DeleteDuplicate(&n, arr);
    for (int i = 0; i < n;i++)
        cout << arr[i] << ' ';
}