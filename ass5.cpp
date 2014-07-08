#include<iostream>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin >> n;
        int x = (n>-1)&&(n%5==0) ? n/5 : -1;
        cout << x << '\n';
    }
    return 0;
}
