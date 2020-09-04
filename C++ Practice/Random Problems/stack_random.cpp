#include <iostream>
#define min(a,b) (a<b?a:b)
using namespace std;
template <class T>
class Stack{
    vetor<T> items;
    friend Stack<T> operator + <>(const Stack<T> &s1, const Stack<T> &s2){
        Stack<T> result = s1;
        for (unsigned i=0; i<s1.items.size(); i++){
            result.items.push_back(s2.items[i]);
        }
        return result;
    }
public:
    bool empty() const {
        return items.empty();
    }
    void push(const T &item){
        items.push_back(item);
    }
    T pop(){
        T last = items.back();
        items.pop_back();
        return last;
    }
};

int main(){
    double a1 = 2.998;
    double b1 = 2.999;
    cout << min(a1,b1) << endl;
    return 0;
}
