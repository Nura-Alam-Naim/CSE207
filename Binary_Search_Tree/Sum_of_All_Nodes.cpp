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
int sum_all(struct node *root)
{
    if(!root)
        return 0;
    ll l = sum_all(root->left);
    ll r = sum_all(root->right);
    return root->value + l + r;
}
int main()
{
    root = insert(root, 5);
    insert(root, 30);
    insert(root, 18);
    insert(root, 20);
    insert(root, 30);
    insert(root, 4);
    cout << sum_all(root) << nl;
}