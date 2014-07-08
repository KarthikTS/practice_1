#include<iostream>
#include<math.h>

using namespace std;

/*program to find first n prime nos*/
int main()
{
    int n;
    cin >> n;

    int cur = 2;
    int i=0;
    for(;i<n;)
    {
        int set=0;
        for(int j=2;j<=(int)sqrt(cur);j++){
            if(cur%j==0){
                set=1;
                break;
            }
        }

        if(set==0){
            cout << cur << '\n';
            i++;
        }

        cur++;

    }

    return 0;
}
