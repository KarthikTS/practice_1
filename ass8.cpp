#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

long double get_pi_value(int no_of_throws)
{
    int darts_in_circle=0;
    srand(time(0));
    for(int i=0;i<no_of_throws;i++)
    {
        double x = rand()/(double)RAND_MAX;
        double y = rand()/(double)RAND_MAX;
        if(sqrt(x*x+y*y) < 1)
            darts_in_circle++;
    }

    return darts_in_circle/static_cast<long double>(no_of_throws) * 4;
}

int get_str_len(const char* s)
{
    int len=0;
    while(*(s+len) != '\0')
        len++;
    return len;
}

void swap(int &p,int &q)
{
    int temp=p;
    p=q;
    q=temp;
}

void swap(int* p,int* q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

void swap(int** p,int** q)
{
    int* temp=*p;
    *p=*q;
    *q=temp;
}

int main()
{
    int no_of_throws;
    cin >> no_of_throws;
    cout << get_pi_value(no_of_throws) << '\n';

    char* s=new char[10];
    cin >> s;
    cout << get_str_len(s) << '\n';

    int a=10,b=20;
    int *p=&a,*q=&b;

    swap(a,b);
    cout << a << '\t' << b << '\n';

    swap(&a,&b);
    cout << a << '\t' << b << '\n';

    swap(&p,&q);
    cout << *p << '\t' << *q << '\n';

    char *oddOreven = "Never odd or even";

    char *c1 = &oddOreven[5];
    c1=c1-2;

    cout << *c1;

    char **c2 = &c1;
    cout << *(*c2);

    c1=c1+2;
    cout << c1-oddOreven;

    return 0;
}
