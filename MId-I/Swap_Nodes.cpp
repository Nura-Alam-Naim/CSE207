//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void push(int n) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = n;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void swap(int x, int y) {
    struct node *temp = head, *temp1 = NULL, *temp1x = NULL, *tempx = NULL, *temp1y = NULL, *tempy = NULL, *temploc = NULL;

    while (temp != NULL) {
        if (temp->data == x) {
            temp1x = temp1;
            tempx = temp;
        }
        if (temp->data == y) {
            temp1y = temp1;
            tempy = temp;
        }
        temp1 = temp;
        temp = temp->next;
    }

    if (tempx == NULL || tempy == NULL) {
        cout << "Value not found" << endl;
        return;
    }

    temploc = tempy->next;

    if (temp1x == NULL)
        head = tempy;
    else
        temp1x->next = tempy;
    tempy->next = tempx->next;
    if (temp1y == NULL)
        head = tempx;
    else
        temp1y->next = tempx;

    tempx->next = temploc;
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(15);
    push(12);
    push(13);
    push(20);
    push(14);
    display();
    swap(12, 20);
    display();
    return 0;
}

