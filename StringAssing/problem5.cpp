#include <iostream>
#include <string>

bool rotateString(std::string s, std::string goal) {
    if (s.length() != goal.length()) {
        return false; // Different lengths, not possible to obtain goal
    }
    
    std::string rotated = s + s;
    
    return rotated.find(goal) != std::string::npos;
}

int main() {
    std::string s = "abcde";
    std::string goal = "cdeab";
    
    bool result = rotateString(s, goal);
    
    std::cout << std::boolalpha << result << std::endl;
    
    return 0;
}
