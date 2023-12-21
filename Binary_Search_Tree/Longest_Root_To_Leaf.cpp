//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    ll value;
    struct node *left = null, *right = null;
} *root;
struct node *insert(struct node *root, ll val)
{
    if (!root)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->value = val;
        return root;
    }
    else if (val < root->value)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
int level(struct node *root)
{
    if (!root)
        return -1;

    int leftHeight = level(root->left);
    int rightHeight = level(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void longest(struct node *root, int *arr, int len)
{
    if (!root)
        return;

    arr[len] = root->value;

    if (!root->left && !root->right)
    {
        for (int i = 0; i <= len; i++)
            cout << arr[i] << ' ';
        cout << nl;
        return;
    }

    ll llv = level(root->left);
    ll rlv = level(root->right);

    if (llv >= rlv)
        longest(root->left, arr, len + 1);
    else
        longest(root->right, arr, len + 1);
}
int main()
{
    root = insert(root, 5);
    insert(root, 30);
    insert(root, 18);
    insert(root, 20);
    insert(root, 30);
    insert(root, 4);
     int arr[7]={0};
    cout << level(root, 0);
    // longest(root, arr, 0);
    // ll i = 0;
    // while(arr[i])
    // {
    //     cout << arr[i] << ' ';
    //     i++;
    // }
}