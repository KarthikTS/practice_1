#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
const int length=4;
const int width=3;

void new_print_array(const int* a,int n)
{
    for(int i=0;i<n;i++)
        i!=n-1?cout << a[i] << ',' : cout << a[i] << '\n';
    return;
}

void transpose(const int a[][length],int b[][width] )
{
    for(int i=0;i<width;i++)
        for(int j=0;j<length;j++)
            b[j][i]=a[i][j];
    return;
}

int main()
{
    srand(time(0));

    int **arr1 = (int**)malloc(sizeof(int*)*width);
    for(int i=0;i<width;i++)
        arr1[i]=(int*)malloc(sizeof(int)*length);
    for(int i=0;i<width;i++)
        for(int j=0;j<length;j++)
            arr1[i][j]=rand();

    int *arr2 = (int*)malloc(sizeof(int)*length*width);
    for(int i=0;i<length;i++)
        for(int j=0;j<width;j++)
            arr2[i*width+j]=0;

    for(int i=0;i<width;i++){
        new_print_array(arr1[i],length);
        cout << '\n';
    }

    transpose(arr1,arr2);

    for(int i=0;i<length;i++){
        new_print_array(&arr2[i],width);
        cout << '\n';
    }

}
