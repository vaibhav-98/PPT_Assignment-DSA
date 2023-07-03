#include <iostream>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false; // Different lengths, not isomorphic
    }
    
    std::unordered_map<char, char> charMap;
    std::unordered_map<char, bool> usedChars;
    
    for (int i = 0; i < s.length(); i++) {
        char sChar = s[i];
        char tChar = t[i];
        
        if (charMap.find(sChar) != charMap.end()) {
            // sChar is already mapped to a character, check if it matches tChar
            if (charMap[sChar] != tChar) {
                return false; // Mismatch, not isomorphic
            }
        } else {
            // sChar is not mapped yet, check if tChar is already used
            if (usedChars[tChar]) {
                return false; // tChar is already used, not isomorphic
            }
            
            charMap[sChar] = tChar; // Map sChar to tChar
            usedChars[tChar] = true; // Mark tChar as used
        }
    }
    
    return true; // All characters mapped correctly, strings are isomorphic
}

int main() {
    std::string s = "egg";
    std::string t = "add";
    
    bool result = isIsomorphic(s, t);
    
    std::cout << std::boolalpha << result << std::endl;
    
    return 0;
}
