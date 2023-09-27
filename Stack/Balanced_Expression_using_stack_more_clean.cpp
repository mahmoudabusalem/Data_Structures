#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isLiftBracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}
bool isRightBracket(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}
bool BracketMatch(char lift , char right) {
    return (right == ')' && lift != '(') ||
           (right == ']' && lift != '[') ||
           (right == '}' && lift != '{');
}

bool is_blanced(string expr) {
    stack<char>s;
    for (char ch : expr) {
        if (isLiftBracket(ch)) {
            s.push(ch);
        }
        if (isRightBracket(ch)) {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if (BracketMatch(top, ch)) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string s;
    cin >> s;
    cout << boolalpha << is_blanced(s) << endl;
    return 0;
}

