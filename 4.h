using namespace std;

class student
{

public:
    char *name;
    int roll_no;

student(){
    name="default";
    roll_no=0;
}

student(char* name,int roll_no)
{
    this->name=name;
    this->roll_no=roll_no;
}

student(const student &o)
{
    str_cpy(&name,o.name);
    roll_no=o.roll_no+1000;
}

void change_details(char* n,int r)
{
    name=n;
    roll_no=r;
    return;
}

void print_info()
{
    cout << name << '\t' << roll_no << '\n' ;
    return;
}

void str_cpy(char**,char*);

};
