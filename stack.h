#include<vector>
using namespace std;

template<typename T> class Stack;

template <typename T>
Stack<T> operator+(const Stack<T> &s1,const Stack<T> &s2){

    Stack<T> result = s1;
    const vector<T> s2_items = s2.get_items();
    for(int i=0;i<s2_items.size();i++)
        result.push(s2_items.at(i));

    return result;
}

template<typename T> Stack<T> operator-(const Stack<T> &,const Stack<T> &);

template <typename T>
class Stack{

template<typename U>
friend Stack<U> operator-(const Stack<U> &,const Stack<U> &);
private:
    vector<T> items;

public:

    bool empty(){ return items.empty(); }

    void push(const T &item){ items.push_back(item); }

    T top() {
            return items.back();
    }

    T pop() {
        T last = items.back();
        items.pop_back();
        return last;
    }

    const vector<T> &get_items() const{ return items; }

};

template<typename T>
Stack<T> operator-(const Stack<T> &s1,const Stack<T> &s2)
{
    Stack<T> result = s1;

    for(int i=0;i<s2.items.size();i++)
        result.items.push_back(s2.items.at(i));

    return result;

}
