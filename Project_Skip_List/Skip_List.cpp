//|ADMIRAL_AUDITORE|//
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
}*head,*tail;

int height = 0;

int Random()
{
    int N = 20;
    int s = (int)rand();
    return (s % N) % 2;
}
struct node* search(int val)
{
    struct node *temp = head;
    while(temp->down!=null)
    {
        temp = temp->down;
        while(val>=temp->next->data)
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

    newHead->data = INT_MIN;
    newTail->data = INT_MAX;

    newHead->next = newTail;
    newTail->previous = newHead;

    newHead->down = head;
    newTail->down = tail;

    head->up = newHead;
    tail->up = newTail;

    head = newHead;
    tail = newTail;
}
void setBeforeAfter(struct node *q, struct node* newNode)
{
    newNode->next = q->next;
    newNode->previous = q;
    q->next->previous = newNode;
    q->next = newNode;
}
void setUpDown(struct node *position, struct node *newNode, struct node *BeforeNew, int val)
{
    if(BeforeNew)
    {
        while(true)
        {
            if(BeforeNew->next->data!=val)
            {
                BeforeNew = BeforeNew->next;
            }
            else
            {
                break;
            }
        }
        newNode->down = BeforeNew->next;
        BeforeNew->next->up = newNode;
    }
    if(position)
    {
        if(position->next->data==val)
        {
            newNode->up = position->next;
        }
    }
} 
struct node *insertAbove(struct node *position, struct node *q, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    struct node *BeforeNew = position->down->down;
    setBeforeAfter(q, newNode);
    setUpDown(position, newNode, BeforeNew, val);
    return newNode;
}
void insert(int val)
{
    struct node *position=search(val);
    struct node *q;
    if(position->data==val)
    {
        return;
    }
    int level = -1;
    int heads = -1;
    do{
        heads++;
        level++;
        if(level>=height)
        {
            height++;
            addlevel();
        }
        q = position;
        while(position->up==null)
        {
            position = position->previous;
        }
        position = position->up;
        q = insertAbove(position, q, val);
    } while (Random());
}

void print()
{
    struct node *highestLevel = head;
    int level = height;

    while (highestLevel != NULL)
    {
        cout << "Level: " << level << nl;

        struct node *current = head;
        while (current != NULL)
        {
            cout << current->data << ' ';

            if (current->next != NULL)
            {
                cout << ": ";
            }

            current = current->next;
        }
        highestLevel = highestLevel->down;
        head = highestLevel;
        level--;
        cout << nl;
    }

    cout << nl;
}
void removeLevel(struct node *rmv)
{
    struct node *temp = rmv->next;
    struct node *temp1 = rmv->previous;
    temp->previous = temp1;
    temp1->next = temp;
    //free(rmv);
}
struct node* removeNode(int val)
{
    struct node *rmv = search(val);
    if(rmv->data!=val)
    {
        return null;
    }
    removeLevel(rmv);
    while(rmv!=null)
    {
        removeLevel(rmv);
        if(rmv->up!=null)
        {
            rmv=rmv->up;
        }
        else
        {
            break;
        }
    }
    return rmv;
}
int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));
    head->data = INT_MIN;
    tail->data = INT_MAX;
    head->next = tail;
    tail->previous = head;
    insert(6);
    insert(15);
    insert(4);
    print();
    removeNode(6);
    print();

    return 0;
}
