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
int sum(struct node *root, int s)
{
    if(!root)
        return s;
    ll l = sum(root->left, s+root->value);
    ll r = sum(root->right, s+root->value);
    return max(l, r);
}
int main()
{
    root = insert(root, 5);
    insert(root, 30);
    insert(root, 18);
    insert(root, 20);
    insert(root, 30);
    insert(root, 4);
    // int arr[7];
    cout << sum(root, 0);
}