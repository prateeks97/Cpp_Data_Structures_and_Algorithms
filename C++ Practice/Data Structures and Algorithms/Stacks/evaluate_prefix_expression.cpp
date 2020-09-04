#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int evaluatePrefix(string s)
{
    stack<int> S;
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (isdigit(s[i])){
            S.push(s[i]-'0');
        }
        else{
            int first = S.top();
            S.pop();
            int second = S.top();
            S.pop();
            int result;
            switch (s[i])
            {
                case '+':
                    S.push(second + first);
                    break;
                case '-':
                    S.push(second - first);
                    break;
                case '*':
                    S.push(second * first);
                    break;
                case '/':
                    S.push(second / first);
                    break;
            }
        }
    }
    return S.top();
}

int main()
{
    string s = "+9*26";
    cout << evaluatePrefix(s) << endl;
    return 0;
}
