#include<iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> a,b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a+b;
    while(!c.empty())
        cout << c.pop() << '\n';
    Stack<int> d = a-b;
    while(!d.empty())
        cout << d.pop() << '\n';
    return 0;
}
