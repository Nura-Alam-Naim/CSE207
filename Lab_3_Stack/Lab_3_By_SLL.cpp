#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll stackSize = 0;
ll total = 0;
bool stack_created = 0;
char str[70];
struct node
{
    int data;
    struct node *next = null;
} *top = null, *temp = null;

void print()
{
    if(!total)
    {
        cout << "Stack is empty" << nl;
        return;
    }
    cout << nl << "Stack looks like: ";
    temp = top;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << nl;
}
void printbin()
{
    cout << nl << "Binary Number: ";
    temp = top;
    while (temp != null)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << nl;
}

void push(int x)
{
    if (total >= stackSize)
    {
        cout << "Stack is full" << nl;
        return;
    }
    total++;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    if (top == null)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    if (!total)
        return -1;
    total--;
    int t = top->data;
    temp = top;
    top = top->next;
    delete temp;
    return t;
}
void clear()
{

    while (top!=null)
    {
        temp = top;
        top = top->next;
        free(temp);
    }
    stackSize = 0;
    stack_created = 0;
    total = 0;
}

int main()
{
    while (true)
    {
        cout <<nl<<"##### MENU #####" nl;
        cout << "1. Insert data/push stack" << nl;
        cout << "2. Print stack" << nl;
        cout << "3. Pop stack" << nl;
        cout << "4. Check parentheses" << nl;
        cout << "5. Convert integer into binary" << nl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
            {
                if(!stack_created)
                {
                    cout << "Enter size of stack: ";
                    cin >> stackSize;
                    stack_created = 1;
                }
                cout << "Enter value: ";
                int c;
                cin >> c;
                cin.ignore();
                push(c);
            }
        else if (choice == 2)
            {
                print();
            }
        else if (choice == 3)
            {
                int c = pop();
                if (c == -1)
                    cout << "Stack is empty" << nl;
                else
                    cout << c << nl;
            }
        else if (choice == 4)
            {
                clear();
                cout << "Enter string: ";
                cin >> str;
                stackSize = strlen(str);
                bool f = 1;
                stack_created = 1;
                for (int i = 0; i < stackSize; i++)
                {
                    if (str[i] == '(')
                        push((int)str[i]);
                    else if (str[i] == ')')
                    {
                        if (pop() == -1)
                        {
                            cout << "Closing parentheses not opened" << nl;
                            f = 0;
                            break;
                        }
                    }
                }
                if (total == 0 && f)
                    cout << "Parentheses are balanced" << nl;
                else if (total > 0)
                    cout << "Opening parentheses not closed" << nl;
            }
        else if (choice == 5)
            {
                clear();
                int num;
                cout << "Enter number: ";
                cin >> num;
                stackSize = num;
                while (num)
                {
                    push(num%2);
                    num /= 2;
                }
                printbin();
            }
        else
            break;
    }

    clear();
    return 0;
}
