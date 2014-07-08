#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int mean=0;
    cin >> mean;
    int max = mean,min=mean;
    for(int i=1;i<n;i++){
        int temp;
        cin >> temp;
        mean+=temp;
        max=max>temp?max:temp;
        min=min<temp?min:temp;
    }

    mean = (double)mean/n;
    int range = max-min;

    cout << mean << '\t' << max << '\t' << min << '\t' << range << '\n';

    return 0;
}
