#include <iostream>
#include <unordered_map>

bool isStrobogrammatic(std::string num) {
    std::unordered_map<char, char> strobogrammaticMap{
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    
    int left = 0;
    int right = num.length() - 1;
    
    while (left <= right) {
        if (strobogrammaticMap.find(num[left]) == strobogrammaticMap.end() || strobogrammaticMap[num[left]] != num[right]) {
            return false; // Invalid pair, not strobogrammatic
        }
        
        left++;
        right--;
    }
    
    return true; // All pairs are valid, num is strobogrammatic
}

int main() {
    std::string num = "69";
    
    bool result = isStrobogrammatic(num);
    
    std::cout << std::boolalpha << result << std::endl;
    
    return 0;
}
