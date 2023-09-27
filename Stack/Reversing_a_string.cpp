#include <iostream>
#include <string>
#define MAX_SIZE 100
using namespace std;

char stack[MAX_SIZE],top=-1;
void push(char item)
{
    if(top>=MAX_SIZE-1)
    {
        cout<<"Stack overflow\n";
        return;
    }
    top++;
    stack[top]=item;
}
char pop()
{
    if(top==-1)
    {
        cout<<"Stack overflow\n";
        return -1;
    }
    return stack[top--];
}
void print_stack() {
    if (top == -1) {
        cout<<"Stack is empty\n";
        return;
    }

    cout<<"Elements in the stack: ";
    for (int i = top; i >= 0; i--) {
        cout<<stack[i];
    }
}

int main()
{
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        push(s[i]);
    }
    print_stack();
    return 0;
}
