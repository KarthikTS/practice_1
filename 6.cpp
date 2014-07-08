#include<iostream>
#include<set>
#include<algorithm>
#include "6.h"
using namespace std;

template <typename T>
T point<T>::get_x(){return x;}

template <typename T>
T point<T>::get_y(){return y;}

struct stp{
int p;
};

container<float> get_float_container(float i){

    container<float> c(i);
    return c;
}

struct stp get_struct(){

    struct stp s = {10};
    return s;

};

int& get_static()
{
    static int i=10;
    return i;
}

int main()
{
    point<int> p(1,2);
    cout << p.get_x() << '\t' << p.get_y() << '\n';
    point_parent<int> *pp = &p;
    point<int> *cp = dynamic_cast<point<int> *>(pp);
    cout << cp->get_x() << "yeah\n";

    struct stp ps = get_struct();
    cout << ps.p << '\n';

    container<float> fcont = get_float_container(0.95);
    cout << fcont.incr() << '\n';

    int j=get_static();
    cout << "j is:" << j << '\n';

    container<int> icont(1);
    container<char> ccont('a');

    cout << icont.incr() << '\n';
    cout << ccont.get_uppercase() << '\n';

    array_type<string,10> str_arr;
    str_arr.set_elt(0,"karthik");
    cout << '\n' << str_arr.get_elt(0);

    array_type<> int_arr;
    int_arr.set_elt(0,1);
    cout << '\n' << int_arr.get_elt(0);

    set<int> iset;
    iset.insert(5);
    iset.insert(4);
    iset.insert(3);
    iset.insert(2);
    iset.insert(1);

    cout << '\n' << *iset.begin();
    cout << '\n' << *iset.end() << '\n';

    set<int>::iterator it;
    it=iset.begin();

    while(it!=iset.end())
        cout << '\n' << *it++;

    int search_for;
    cin >> search_for;
    if(binary_search(iset.begin(),iset.end(),search_for))
        cout << "found";
    else
        cout << "not found";

    UScurrency a = {2,50};
    UScurrency b = {4,75};
    UScurrency c = a+b;
    cout << '\n' << c.dollars << "." << c.cents << '\n';

    return 0;
}
