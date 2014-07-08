#include<iostream>
using namespace std;

class CDummy{

public:
static int n;
CDummy(){n++;}
~CDummy(){n--;}

};

int* get_pointer_to_five()
{
    int* x=new int;
    *x=5;
    return x;
}

class vehicle{

    public:
        int color_code,model_code;

        vehicle(int c,int m):color_code(c),model_code(m){
            cout << color_code << model_code << '\n';
        }

        virtual char* get_code()
        {
            return "parent";
        }

        virtual void no_def_func() = 0;
};

class car: public vehicle{

public:
    char* model_name;

    car(char* n,int c,int m): model_name(n),vehicle(c,m) {
        cout << model_name << '\n';
    }

    char* get_code()
    {
        return "child";
    }

    void no_def_func(){return;}

    ~car(){cout << '\n' << model_code << "car destructor called\n" ;}

};

int CDummy::n = 0;

template <typename T,typename U>
U get_sum(T a,T b)
{
    return a+b;
}

int main()
{
    cout << get_sum<double,double>(1.1,(double)2) << '\n';

    car c("city",01,101);
    vehicle *v1 = &c;
    char* n = v1->get_code();
    cout << n;
    vehicle &v2=c;
    cout << v2.get_code();


    int *p=get_pointer_to_five();
    cout << *p;
    delete p;


    int no;
    cout << "how many items?:";
    cin >> no;
    int *arr = new int[no];
    for(int i=0;i<no;i++)
        cin >> arr[i];
    for(int i=0;i<no;i++)
        cout << arr[i];
    delete[] arr;

    car *car_1 = new car("blaze",01,111);
    cout << car_1->model_code;
    delete car_1;

    CDummy *c1 = new CDummy;
    cout << CDummy::n << "k";
    delete c1;
    cout << CDummy::n << "l";
    return 0;
}
