#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    //Write your code here
    vector<char> stack_v;
    vector<char> queue_v;
public:
    void pushCharacter(char c)
    {
        stack_v.push_back(c);
    }
    void enqueueCharacter(char c)
    {
        queue_v.push_back(c);
    }
    char popCharacter()
    {
        char top = stack_v.front();
        stack_v.pop_back();
        return top;
    }
    char dequeueCharacter()
    {
        char temp = queue_v[queue_v.size()-1];
        queue_v.erase(queue_v.begin()+queue_v.size()-2);
        return temp;
    }
    void Print()
    {
        for (int i=0; i<stack_v.size();i++)
        {
            cout << stack_v[i] << " ";
        }
        cout << "   ----Stack"<<endl;
        for (int i=0; i<queue_v.size();i++)
        {
            cout << queue_v[i] << " ";
        }
        cout << "   ----Queue"<<endl;
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);

  	// create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    obj.Print();

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
