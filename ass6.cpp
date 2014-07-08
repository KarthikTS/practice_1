#include<iostream>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin >> n;

        if(n<0)
            break;

        if( !((n>-1)&&(n%5==0)) )
            continue;

        cout << n/5 << '\n';

    }
    cout << "GoodBye\n";
    return 0;
}

