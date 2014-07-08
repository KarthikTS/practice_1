#include<iostream>
#include "mylib.h"

using namespace std;

void f1(int x)
{
    cout << x << '\n';
    return;
}

void f1(int x,int y)
{
    cout << x << '\t' << y << '\n';
    return;
}
