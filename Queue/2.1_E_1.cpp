#include<iostream>
using namespace std;
#define s 10
class queue{
    int front;
    int rear;
    int len;
    int total;
    int *arr ;

public:
    queue();
    ~queue();
    void push(int num);
    int pop();
    bool empty();
    bool full();
    int size();
};
queue::queue()
{
        front = -1;
        rear = -1;
        len = s;
        total = 0;
        arr=(int* )malloc(s*sizeof(int));
}
queue::~queue(){
        front = -1;
        rear = -1;
        len = s;
        total = 0;
        free(arr);
}
bool queue::full()
{
        return total >= s;
}
void queue::push(int num)
{
    
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
    }
    else
        rear = (rear + 1) % s;
    arr[rear] = num;
    total++;
}
bool queue:: empty()
{
    return total <= 0;
}
int queue::pop()
{
    int ret = 0;
    if(rear==front)
    {
        ret = arr[front];
        front = -1;
        rear = -1;
        total = 0;
    }
    else{
        ret = arr[front];
        front = (front + 1) % s;
        total--;
    }
    return ret;
}
int queue::size()
{
    return s;
}
int main()
{
    queue q1, q2;
    q1.push(5);
    q1.push(6);
    q1.push(7);
    q2.push(100);
    q2.push(98);
    q2.push(94);
    cout << q1.size()<<' ';
    cout << q2.size() << ' ';
    cout << '\n';
    while(!q1.empty())
        cout << q1.pop() << ' ';
    cout << '\n';
    while (!q2.empty())
        cout << q2.pop() << ' ';
}


