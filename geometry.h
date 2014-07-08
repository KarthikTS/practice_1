#include<iostream>
using namespace std;

class Point{

private:
    int x;
    int y;

public:
    Point(int x=0,int y=0): x(x),y(y){ }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(const int new_x) { x=new_x; }
    void setY(const int new_y) { y=new_y; }

};

class PointArray{

private:
    int size;
    Point *points;

    void resize(const int n){
        if(n>=0){
            Point* pts = new Point[n];
            int min = (n > size ? size : n);
            for(int i=0;i<min;i++)
                pts[i]=points[i];
            delete[] points;
            size=n;
            points=pts;
        }
    }

public:
    PointArray(){
        size=0;
        points=new Point[0];
    }

    PointArray(const Point points[],const int size):size(size){
        this->points = new Point[size];
        for(int i=0;i<size;i++)
            this->points[i]=points[i];
    }

    PointArray(const PointArray &pa){
        size=pa.size;
        points=new Point[size];
        for(int i=0;i<size;i++){
            points[i]=pa.points[i];
        }
    }

    int get_size () const
    {
        return size;
    }

    void clear()
    {
        resize(0);
        return;
    }

    void push_back(const Point &p)
    {
        resize(size+1);
        points[size-1]=p;
        return;
    }

    void insert(const int position,const Point &p)
    {
        resize(size+1);
        for(int i=size-1;i>=position;i--)
            points[i]=points[i-1];
        if(position>0)
            points[position-1]=p;
        return;
    }

    void remove(const int position)
    {
        for(int i=position-1;i<size-1;i++)
            points[i]=points[i+1];
        if(size>0)
            resize(size-1);
        return;
    }

    Point* get(const int pos)
    {
        return pos>0 && pos<=size ? points+pos-1 : NULL;
    }

    const Point* get(const int pos) const
    {
        return pos>0 && pos<=size ? points+pos-1 : NULL;
    }

    ~PointArray(){
        delete[] points;
    }

};

class Polygon{

protected:
    PointArray points;
    static int no_of_polygons;

public:
    Polygon(const Point ps[],const int len) : points(ps,len) {
        ++no_of_polygons;
        }

    Polygon(const PointArray &pa) : points(pa) {
        ++no_of_polygons;
        }

    virtual double area() const = 0;

    static int getNumPolygons() {
        return no_of_polygons;
        }

    int getNumSides() const {
        return points.get_size();
        }

    const PointArray* getpoints() const {
        return &points;
        }

    virtual ~Polygon(){ --no_of_polygons; }

};
