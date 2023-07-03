#include <iostream>
#include <algorithm>

std::string addStrings(std::string num1, std::string num2) {
    std::string sum;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
        int currentSum = digit1 + digit2 + carry;
        
        carry = currentSum / 10;
        int digitSum = currentSum % 10;
        
        sum.push_back('0' + digitSum);
        
        i--;
        j--;
    }
    
    std::reverse(sum.begin(), sum.end());
    
    return sum;
}

int main() {
    std::string num1 = "11";
    std::string num2 = "123";
    
    std::string result = addStrings(num1, num2);
    
    std::cout << result << std::endl;
    
    return 0;
}
