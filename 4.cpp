#include<iostream>
#include<malloc.h>
#include "4.h"

int str_len(char* s)
{
    int len=0;
    while(*s++)
        len++;

    return len;
}

void student::str_cpy(char **dest,char* src)
{
    *dest = (char*)malloc(sizeof(char)*str_len(src));
    char *temp=*dest;
    while(*src)
    {
        *temp++ = *src++;
    }

    *temp='\0';
    return;
}

int main()
{
    student s1,s2("karthik",8);
    s1("ac",12);
    s1.name="surya";
    s1.roll_no=1234;

    s1.print_info();
    s2.print_info();

    s1.change_details("jai_ram",90);
    s1.print_info();

    student &s3=s1;
    s3.name="hari";
    s3.print_info();
    s1.print_info();

    student s4=s2;
    s4.print_info();

    s1=student(s2);
    s1.print_info();

    char f_name[]="stud";
    student s6;
    s6.print_info();
    s6.name=f_name;
    student s7=s6;
    s7.name[2]='n';
    s7.print_info();
    s6.print_info();
    f_name[3]='p';
    s6.print_info();
    cout << f_name << '\n';

    return 0;
}
