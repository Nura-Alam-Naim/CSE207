//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node{
    int data;
    struct node *left=null,*right=null;
} *root;
struct node* insert(struct node *root, int val)
{
    if(!root)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = val;
        return root;
    }
    else if(val<root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void preorder(struct node *root)
{
    if(!root)
        return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
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
    preorder(root);
}