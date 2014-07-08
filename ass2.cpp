#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i=0;

    for(;i++<n;)
        cout << i;

    cout << "***********************\n";

    i=0;
    while(i++<n){
        cout << i;
    }

    cout << "***********************\n";

    i=0;
    do{
        cout << ++i;
    }while(i<n);

    cout << "***********************\n";

    {
        char i='a';
        n=10;
        cout << i << '\n';
    }

        cout << i << '\n';
        cout << n << '\n';
    return 0;
}
