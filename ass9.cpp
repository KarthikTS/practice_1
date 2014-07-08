#include<iostream>
#include<string>
#include<cmath>
#include<typeinfo>
#include "geometry.h"
using namespace std;
#define min(x,y) (x<y?:x:y)

const string vowles="aeiou";
string pigLatinify(const string s)
{
    if(s.size()==0)
        return s;

    if(s.find("qu")==0)
        return s.substr(2,s.size()-2)+"-"+s.substr(0,2)+"ay";
    else if(vowles.find(s[0])!=string::npos)
        return s+"way";
    else
        return s.substr(1,s.size()-1)+"-"+s.substr(0,1)+"ay";

}

int Polygon::no_of_polygons=0;

Point constructorPoints[4];

Point* updateconstructorPoints(const Point &p1,const Point &p2,const Point &p3,const Point &p4=Point(0,0)){

    constructorPoints[0]=p1;
    constructorPoints[1]=p2;
    constructorPoints[2]=p3;
    constructorPoints[3]=p4;
    return constructorPoints;

}

class Rectangle : public Polygon{

public:
    Rectangle(const Point &p1,const Point &p2) : Polygon(updateconstructorPoints(p1 , Point(p1.getX(),p2.getY()) ,
                                                                               p2 , Point(p2.getX(),p1.getY()) ), 4 ){
    }

    Rectangle(const int ax,const int ay,const int bx,const int by) : Polygon( updateconstructorPoints(Point(ax,ay), Point(ax,by) ,
                                                                             Point(bx,by), Point(bx,ay) ) , 4) {
    }

    double area() const{
        int len=0,wid=0;
        len = points.get(4)->getX() - points.get(1)->getX();
        wid = points.get(2)->getY() - points.get(1)->getY();
        return (double)len*wid;
    }

};

class Triangle : public Polygon{

public:
    Triangle(const Point &p1,const Point &p2,const Point &p3) : Polygon( updateconstructorPoints(p1,p2,p3), 3 ) {
    }

    double area() const {
        int dx01 = points.get(1) ->getX() -points.get(2) ->getX(),
            dx12 = points.get(2) ->getX() -points.get(3) ->getX(),
            dx20 = points.get(3) ->getX() -points.get(1) ->getX();
        int dy01 = points.get(1) ->getY() -points.get(2) ->getY(),
            dy12 = points.get(2) ->getY() -points.get(3) ->getY(),
            dy20 = points.get(3) ->getY() -points.get(1) ->getY();

        double a = sqrt(dx01*dx01 + dy01*dy01),
               b = sqrt(dx12*dx12 + dy12*dy12),
               c = sqrt(dx20*dx20 + dy20*dy20);

        double s=(a +b+c) /2;

        return sqrt( s * (s-a) * (s-b) * (s-c) );
    }

};

void printAttributes(Polygon *p){

    double area = p->area();
    const PointArray *pa = p->getpoints();
    cout << "the points are:\n";
    for(int i=1;i<=pa->get_size();i++)
        cout << pa->get(i)->getX() << '\t' << pa->get(i)->getY() << '\n';
    cout << "the area is :" << area << '\n';
    return;
}

template <typename T>
T minimum(const T a,const T b){
    return a<b?a:b;
}

int main(){

    PointArray points1;
    PointArray points2 = points1;
    points2.push_back(Point(1,2));
    points2.push_back(Point(3,4));
    points2.insert(2,Point(5,6));
    points2.insert(1,Point(7,8));
    cout << points1.get_size() << '\n';
    cout << points2.get_size() << '\n';

    for(int i=1;i<=points2.get_size();i++){
        cout << points2.get(i)->getX() << '\t';
        cout << points2.get(i)->getY() << '\n';
    }

    int size = points2.get_size();
    while(size)
        points2.remove(size--);
    cout << points2.get_size() << '\n';
    points1.clear();

    string str = "askjnvk";
    cout << pigLatinify(str) << '\n';

    cout << "Enter lower left and upper right coords of rectangle as four space separated integers: ";
    int llx, lly, urx, ury;
    cin >> llx >> lly >> urx >> ury;
    Point ll(llx, lly), ur(urx, ury);
    Rectangle r(ll, ur);
    printAttributes(&r);

    cout << "Enter three coords of triangle as six space separated integers: ";
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    Triangle t(a, b, c);
    printAttributes(&t);

    Triangle *t1 = new Triangle(a,b,c);
    Polygon *pt1 = t1;
    cout << pt1->area() << '\n';

    Triangle t2(a,b,c);
    Polygon *pt2 = &t2;
    cout << pt2->area() << '\n';

    return 0;
}
