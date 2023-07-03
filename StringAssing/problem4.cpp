#include <iostream>
#include <sstream>

std::string reverseWords(std::string s) {
    std::istringstream iss(s);
    std::string word;
    std::string reversedSentence;
    
    while (iss >> word) {
        std::reverse(word.begin(), word.end());
        reversedSentence += word + ' ';
    }
    
    // Remove trailing whitespace
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }
    
    return reversedSentence;
}

int main() {
    std::string s = "Let's take LeetCode contest";
    
    std::string result = reverseWords(s);
    
    std::cout << result << std::endl;
    
    return 0;
}
