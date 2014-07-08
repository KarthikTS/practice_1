#include<iostream>

using namespace std;
#define cons 10.0

int main()
{
    cout << "Hello world \n";
    cout << -1 << "\n";
    cout << 2%6 << "\n";
    cout << -10%6 << "\n";

    unsigned char c = -158;
    cout << c << '\n';

    short int i1=10;
    long int i2=11;
    long long int i3=12;
    cout << sizeof(i1) << sizeof(i2) << sizeof(i3) << '\n';

    float j1=10.1;
    double j2=11.1;
    long double j3=12.1;
    cout << sizeof(j1) << sizeof(j2) << sizeof(j3) << '\n';

    char d='p';
    cout << !d;

    int x;
    int y = (x=5);
    cout << y << '\n';

    return 0;
}
