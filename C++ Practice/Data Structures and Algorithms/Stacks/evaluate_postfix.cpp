#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string s)
{
    stack<int> operands;
    for (int i = 0; i<s.size(); ++i){
        if (isdigit(s[i])){
            operands.push(s[i]-'0');
        }
        else {
            int first = operands.top();
            operands.pop();
            int second = operands.top();
            operands.pop();
            int result;
            switch (s[i])
            {
                case '+':
                    operands.push(second + first);
                    break;
                case '-':
                    operands.push(second - first);
                    break;
                case '*':
                    operands.push(second * first);
                    break;
                case '/':
                    operands.push(second / first);
                    break;
            }
        }
    }
    return operands.top();
}

int main()
{
    string s = "231*+9-";
    string s1 = "123*+5-";
    cout << evaluatePostfix(s1)<< endl;
    return 0;
}
