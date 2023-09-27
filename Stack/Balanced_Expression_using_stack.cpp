#include <iostream>
#include <iostream>
#include <string>
#include <stack>
#define MAX_SIZE 100
using namespace std;

void check_balanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{' || c=='<') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}' || c=='>') {
            if (s.empty()) {
                cout << "Expression is not balanced" << endl;
                return;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                cout << "Expression is not balanced" << endl;
                return;
            }
        }
    }
    if (s.empty()) {
        cout << "Expression is balanced" << endl;
    } else {
        cout << "Expression is not balanced" << endl;
    }
}

int main()
{
    string s;
    cin>>s;
    check_balanced(s);
    return 0;
}
