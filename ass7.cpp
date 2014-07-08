#include <iostream >

using namespace std;

int main()
{

    long long int accumulator = 1;
    int number;
    cin >> number;

    if(number<0){
        cout << "factorial not supported for negative nos\n";
        return 1;
    }
    if(number>20){
        cout << "factorial not supported for nos > 20\n";
        return 1;
    }

    for(;number>0;accumulator*=number--);
    cout << "result is:" << accumulator << '\n';

    return 0;
}
