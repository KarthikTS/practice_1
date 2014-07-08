#include<cctype>
using namespace std;

struct UScurrency{
int dollars;
int cents;
};

UScurrency operator+(UScurrency m,UScurrency n)
{
    UScurrency temp = {0,0};
    temp.dollars = m.dollars + n.dollars;
    temp.cents = m.cents + n.cents;
    if(temp.cents>=100)
    {
        temp.dollars+=1;
        temp.cents-=100;
    }
    return temp;
}

template <typename T>
class point_parent{

public:
    point_parent(){ cout << "point parent cons called\n"; }
    point_parent(T x,T y){
        cout << x << "\t" << y << '\n';
    }
    virtual void abc(){}

};

template <typename T>
class point:public point_parent<T>{

private:
    T x,y;
public:
    point(T x,T y) : point_parent<T>(x,y),x(x),y(y) { }
    point(){ cout << "no arg constructor called\n"; }
    T get_x();
    T get_y();

};

template <typename T>
class container {
private:
    T elt;
public:
    container(T elt): elt(elt) { }
    T incr() { return ++elt; }
};

template<>
class container<char> {

private:
    char elt;
public:
    container(char elt): elt(elt) {}
    char get_uppercase(){return toupper(elt);}
};

template <typename T=int,int N=10>
class array_type{

friend container<T>;
private:
    T elt[N];
public:
    void set_elt(int i,T val){ elt[i]=val;}
    T get_elt(int i){ return elt[i];}

};
