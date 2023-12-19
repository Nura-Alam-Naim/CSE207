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
} *root = null, *temp = null;
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
void inorder(struct node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << ' ';
}
void preorder(struct node *root)
{
    if (!root)
        return;
    cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}
struct node *search(struct node *root, ll val)
{
    if (!root || root->value == val)
        return root;
    else if (root->value > val)
        return search(root->left, val);
    else
        return search(root->right, val);
}
struct node *searchMax(struct node *root)
{
    if (!root->right)
    {
        // cout << root->value << nl;
        return root;
    }
    
    return searchMax(root->right);
}
struct node *searchMin(struct node *root)
{
    if (!root->left)
    {
        // cout << root->value << nl;
        return root;
    }
    return searchMin(root->left);
}
struct node *Delete(struct node *root, ll val)
{
    if (!root)
        return root;

    if (root->value > val)
        root->left = Delete(root->left, val);
    else if (root->value < val)
        root->right = Delete(root->right, val);
    else
    {
        if (!root->left)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            temp = searchMin(root->right);
            root->value = temp->value;
            root->right = Delete(root->right, temp->value);
        }
        
    }
    return root;
}

int main()
{
    ll choice, num;
    while (true)
    {
        cout << nl<<nl;
        cout << 1 << ".Insert to BST." << nl;
        cout << 2 << ".Print Preorder of BST." << nl;
        cout << 3 << ".Print Inorder of BST." << nl;
        cout << 4 << ".Print Postorder of BST." << nl;
        cout << 5 << ".Search element in BST." << nl;
        cout << 6 << ".Print Mininum value of BST." << nl;
        cout << 7 << ".Print Maximum value of BST." << nl;
        cout << 8 << ".Delete value from BST" << nl;
        cout << "#Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value to insert: ";
            cin >> num;
            if (!root)
                root = insert(root, num);
            else
                insert(root, num);
        }
        else if (choice == 2)
        {
            preorder(root);
        }
        else if (choice == 3)
        {
            inorder(root);
        }
        else if (choice == 4)
        {
            postorder(root);
        }
        else if (choice == 5)
        {
            cout << "Enter value to search: ";
            cin >> num;
            if (search(root, num))
                cout << "Number is present" << nl;
            else
                cout << "Number is not present" << nl;
        }
        else if (choice == 6)
        {
            struct node *temp1=searchMin(root);
            cout << temp1->value << nl;
        }
        else if (choice == 7)
        {
            struct node *temp1 = searchMax(root);
            cout << temp1->value << nl;
        }
        else if (choice == 8)
        {
            cout << "Enter value to Delete: ";
            cin >> num;
            if(!root)
                cout << "Tree is empty" << nl;
            Delete(root, num);
        }
    }
}