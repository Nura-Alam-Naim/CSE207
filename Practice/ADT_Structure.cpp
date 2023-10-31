//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
typedef struct node{
    void *val;
    struct node *next;
} NODE;
NODE* newNode(void* data)
{
    NODE *newNd = (NODE *)malloc(sizeof(NODE));
    newNd->val = data;
    newNd->next = null;
    return newNd;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int *value=(int*)malloc(sizeof(int));
    *value = 7;
    NODE *node = newNode(value);
    cout <<"Value in node 1: "<< *((int*)(node->val)) << nl;
    int *newval = (int *)malloc(sizeof(int));
    *newval = 75;
    NODE *newNod = newNode(newval);
    cout << "Value in node 2: " << *((int *)(newNod->val))<<nl;
}