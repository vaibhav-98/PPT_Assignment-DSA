#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    
    if (s.empty() || p.empty() || s.length() < p.length())
        return result;
    
    unordered_map<char, int> pFreq, sFreq;
    int pLength = p.length();
    int sLength = s.length();
    
    // Count the frequencies of characters in p
    for (char c : p)
        pFreq[c]++;
    
    // Initialize the sliding window with the first pLength characters of s
    for (int i = 0; i < pLength; i++)
        sFreq[s[i]]++;
    
    // Compare the frequencies of characters in the sliding window with pFreq
    for (int i = pLength; i <= sLength; i++) {
        // If the frequencies match, add the start index of the window to the result
        if (pFreq == sFreq)
            result.push_back(i - pLength);
        
        // Move the sliding window by removing the character at the beginning
        // and adding the character at the current position
        if (i < sLength) {
            sFreq[s[i - pLength]]--;
            if (sFreq[s[i - pLength]] == 0)
                sFreq.erase(s[i - pLength]);
            sFreq[s[i]]++;
        }
    }
    
    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);
    
    cout << "Start indices of p's anagrams: ";
    for (int index : result)
        cout << index << " ";
    cout << endl;
    
    return 0;
}
