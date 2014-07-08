#include<iostream>
#include<cstdlib>
#include<ctime>

#include "mylib.cpp"

using namespace std;

void increment(int &a)
{
    a=a+1;
    return;
}

void swap(int &p,int &q)
{
    int t;
    t=p;
    p=q;
    q=t;
    return;
}

void print_array(const int *a,const int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout << a[i] << '\n';

    a=a+2;
    cout << *a << '\n';

    return;
}

int get_random_no()
{
    srand(time(0));
    int rand_no = rand();
    return rand_no;
}

void set_string(char **str_ptr)
{
    int x;
    cin >> x;

    if(x<0)
        *str_ptr = "negative";
    else
        *str_ptr = "non_negative";

    return;

}

int return_sum(const int ar[],int arr_len)
{
    return arr_len==0?0:ar[0]+return_sum(ar+1,arr_len-1);

}

void new_print_array(const int* a,int n)
{
    for(int i=0;i<n;i++)
        i!=n-1?cout << a[i] << ',' : cout << a[i] << '\n';
    return;
}

const int length=4;
const int width=3;

void transpose(const int a[][length],int b[][width] )
{
    for(int i=0;i<width;i++)
        for(int j=0;j<length;j++)
            b[j][i]=a[i][j];
    return;
}

void reverse_array(int* a,const int n)
{
    int i,j;
    if(n%2==1){
        j=n/2+1;
        i=j-2;
    }
    else{
        j=n/2;
        i=j-1;
    }

    while(j!=n)
    {
        int temp = a[j];
        a[j]=a[i];
        a[i]=temp;
        j++;i--;
    }

    return;
}

int main()
{
    f1(1);
    f1(1,2);

    int p=1;
    increment(p);
    cout << p << '\n';
    int a=1,b=2;
    swap(a,b);
    cout << a << '\n' << b << '\n';

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    print_array(arr,arr,n);
    reverse_array(arr,n);
    new_print_array(arr,n);
    cout << "the sum of array is\n" << return_sum(arr,n) << '\n';

    int y=5;
    int &x = y;

    cout << "x=" << x << '\n';
    cout << "y=" << y << '\n';

    x=10;

    cout << "x=" << x << '\n';
    cout << "y=" << y << '\n';

    int &z=x;
    z=30;

    cout << "x=" << x << '\n';
    cout << "y=" << y << '\n';
    cout << "z=" << z << '\n';

    int q=9;
    x=q;

    cout << "x=" << x << '\n';
    cout << "y=" << y << '\n';
    cout << "z=" << z << '\n';

    char *ch = "abc";
    cout << ch[1];

    cout << get_random_no() << '\n';

    char *str;
    set_string(&str);
    cout << str << '\n';

    const char *str_names[] = {"c","s","d","b"};
    cout << "enter a no:(1-4):";
    unsigned int xr;
    cin >> xr;
    if(xr<=4 && xr>=1)
        cout << *str_names[xr-1];

    int por = (int)10.0;
    cout << por;

    return 0;
}
