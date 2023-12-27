#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
struct node
{
    int data;
    struct node *next = null;
    struct node *previous = null;
    struct node *up = null;
    struct node *down = null;
};
struct node *head = (struct node *)malloc(sizeof(struct node));
struct node *tail = (struct node *)malloc(sizeof(struct node));
void setVal(struct node *head, struct node *tail)
{
    head->data = INT_MIN;
    tail->data = INT_MAX;
    head->next = tail;
    tail->previous = head;
}
int height = 0;
int Random()
{
    return ((int)rand() % 20) % 2;
}
struct node *search(int val)
{
    struct node *temp = head;
    while (temp->down != null)
    {
        temp = temp->down;
        while (val >= temp->next->data)
        {
            temp = temp->next;
        }
    }
    return temp;
}
void addlevel()
{
    struct node *newHead = (struct node *)malloc(sizeof(struct node));
    struct node *newTail = (struct node *)malloc(sizeof(struct node));
    setVal(newHead, newTail);
    newHead->down = head;
    newTail->down = tail;

    head->up = newHead;
    tail->up = newTail;

    head = newHead;
    tail = newTail;
}
void setUpDown(struct node *pos, struct node *newNode, struct node *BeforeNew, int val)
{
    if (BeforeNew)
    {
        while (true)
            if (BeforeNew->next->data != val)
                BeforeNew = BeforeNew->next;
            else
                break;
                
        newNode->down = BeforeNew->next;
        BeforeNew->next->up = newNode;
    }
    if (pos && pos->next->data == val)
            newNode->up = pos->next;
}
struct node *insertAbove(struct node *pos, struct node *q, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = q->next;
    newNode->previous = q;
    q->next->previous = newNode;
    q->next = newNode;
    struct node *BeforeNew = pos->down->down;
    setUpDown(pos, newNode, BeforeNew, val);
    return newNode;
}
void insert(int val)
{
    struct node *pos = search(val);
    struct node *q;
    if (pos->data == val)
        return;
    int level = -1;
    do
    {
        level++;
        if (level >= height)
        {
            height++;
            addlevel();
        }
        q = pos;
        while (pos->up == null)
            pos = pos->previous;
        pos = pos->up;
        q = insertAbove(pos, q, val);
    } while (Random());
}

void print()
{
    struct node *maxLvl = head;
    int level = height;
    cout << nl;
    while (maxLvl != NULL)
    {
        cout << "\t#Level: " << level << nl;
        struct node *temp = maxLvl;
        while (temp != NULL)
        {
            if(temp->data== -2147483648)
                cout << "HEAD" << ' ';
            else if (temp->data == 2147483647)
                cout << "Tail" << ' ';
            else
                cout << temp->data;
            if (temp->next != NULL)
                cout << ": ";
            temp = temp->next;
        }
        maxLvl = maxLvl->down;
        temp = maxLvl;
        level--;
        cout << nl;
    }
    cout << nl;
}
struct node *removeLevel(struct node *rmv)
{
    struct node *temp = rmv->next;
    struct node *temp1 = rmv->previous;
    temp->previous = temp1;
    temp1->next = temp;
    free(rmv);
    rmv = null;
    return rmv;
}
void remove(int val)
{
    struct node *rmv = search(val);
    rmv = removeLevel(rmv);
    while (rmv != null)
    {
        if (rmv->up != null)
        {
            rmv = rmv->up;
        }
        else
        {
            break;
        }
    }
}
int main()
{
    setVal(head, tail);
    while(true)
    {
        cout << 1 << ". Insert data: " << nl;
        cout << 2 << ". Delete data: " << nl;
        cout << 3 << ". Search data: " << nl;
        cout << 4 << ". Exit: " << nl;
        cout << "#Enter Choice: ";
        int n, c;
        cin >> n;
        if(n==1)
        {
            cout << "Enter value to INSERT: ";
            cin >> c;
            insert(c);
            print();
        }
        else if(n==2)
        {
            cout << "Enter value to DELETE: ";
            cin >> c;
            remove(c);
            print();
        }
        else if(n==3)
        {
            cout << "Enter value to SEARCH: ";
            cin >> c;
            struct node *temp = search(c);
            if(!temp)
                cout << c << " is not in the list" << nl;
            else
                cout << c << " is in the list" << nl;
            print();
        }
        else
            break;
    }
    
}