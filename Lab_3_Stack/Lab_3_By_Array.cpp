//|ADMIRAL AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define null NULL
ll len;
ll top = -1;
bool created = 0;
char stk[5000], str[50];
void clear()
{
    for (int i = 0; i < top; i++)
        stk[i] = '\0';
    len = 0;
    top = -1;
    created = 0;
}
void print()
{
    if (top = -1)
    {
        cout << "Stack is empty" << nl;
        return;
    }
    cout << nl << "Stack looks like: ";
    for (int i = top; i >= -1; i--)
        cout << stk[i] << " ";
    cout << nl;
}
void printbin()
{
    cout << nl << "Binary number: ";
    for (int i = top; i >= -1; i--)
        cout << stk[i];
    cout << nl;
}
void push(char c)
{
    if (top + 1 == len)
    {
        cout << "Stack Overflow";
        return;
    }
    top++;
    stk[top] = c;
}
char pop()
{
    if (top == -1)
        return '\0';
    char c = stk[top];
    stk[top] = '\0';
    top--;
    return c;
}
int main()
{
    while (true)
    {
        cout << nl << "##### MENU #####" nl;
        cout << "1. Create new stack" << nl;
        cout << "2. Insert data/push stack" << nl;
        cout << "3. Print stack" << nl;
        cout << "4. Pop stack" << nl;
        cout << "5. Check parentheses" << nl;
        cout << "6. Convert integer into binary" << nl;
        char choice;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == '1')
        {
            clear();
            cout << "Enter size of stack: ";
            cin >> len;
        }
        else if (choice == '2')
        {
            cout << "Enter value: ";
            char c;
            cin >> c;
            cin.ignore();
            push(c);
        }
        else if (choice == '3')
        {
            print();
        }
        else if (choice == '4')
        {
            char c = pop();
            if (c == '\0')
                cout << "Stack is empty" << nl;
            else
                cout << c << nl;
        }
        else if (choice == '5')
        {
            clear();
            cout << "Enter string: ";
            cin >> str;
            len = strlen(str);
            bool f = 1;
            created = 1;
            for (int i = 0; i < len; i++)
            {
                if (str[i] == '(')
                    push(str[i]);
                else if (str[i] == ')')
                {
                    if (pop() == '\0')
                    {
                        cout << "Closing parentheses not opened" << nl;
                        f = 0;
                        break;
                    }
                }
            }
            if (top == -1 && f)
                cout << "Parentheses are balanced" << nl;
            else if (top > -1)
                cout << "Opening parentheses not closed" << nl;
        }
        else if (choice == '6')
        {
            clear();
            int num;
            cout << "Enter number: ";
            cin >> num;
            len = num;
            while (num)
            {
                push((num % 2 + '0'));
                num /= 2;
            }
            printbin();
        }
        else
            break;
    }
}
