#include<iostream>
#include "geometry.h"
using namespace std;

int Point::getX() const{ return x; }
int Point::getY() const{ return y; }
void Point::setX(const int new_x){ x=new_x; }
void Point::setY(const int new_y){ y=new_y; }

int main()
{
    Point p1(1,2);
    cout << p1.getX() << '\t' << p1.getY() << '\n';
    p1.setX(4);
    p1.setY(5);
    cout << p1.getX() << '\t' << p1.getY();
    return 0;
}


