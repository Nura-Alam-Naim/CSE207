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
void printAll(struct node *root, int *arr,int len)
{
    if(!root)
        return;
    if(!root->left && !root->right)
    {
        for (int i = 0; i < len;i++)
            cout << arr[i] << ' ';
        cout << root->value << nl;
        return;
    }
    arr[len] = root->value;
    printAll(root->left, arr, len + 1);
    printAll(root->right, arr, len + 1);
}
int main()
{
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 30);
    insert(root, 18);
    insert(root, 20);
    insert(root, 30);
    insert(root, 4);
    int arr[7];
    printAll(root, arr, 0);
}