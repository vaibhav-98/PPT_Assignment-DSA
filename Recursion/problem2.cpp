#include <stack>
#include <iostream>

bool checkValidString(string s) {
    stack<int> leftStack, starStack;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            leftStack.push(i);
        } else if (s[i] == '*') {
            starStack.push(i);
        } else {
            if (!leftStack.empty()) {
                leftStack.pop();
            } else if (!starStack.empty()) {
                starStack.pop();
            } else {
                return false;
            }
        }
    }
    
    while (!leftStack.empty() && !starStack.empty()) {
        if (leftStack.top() > starStack.top()) {
            return false;
        }
        leftStack.pop();
        starStack.pop();
    }
    
    return leftStack.empty();
}

int main() {
    string s = "()";
    if (checkValidString(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    
    return 0;
}
