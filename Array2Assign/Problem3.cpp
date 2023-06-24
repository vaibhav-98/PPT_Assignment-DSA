#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <algorithm>

int findLHS(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    
    
    for (int num : nums) {
        freqMap[num]++;
    }
    
    int maxLen = 0;
    
    
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
        int num = it->first;
        int freq = it->second;
        
        if (freqMap.count(num + 1) > 0) {
            int currLen = freq + freqMap[num + 1];
            maxLen = max(maxLen, currLen);
        }
    }
    
    return maxLen;
}




int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int result = findLHS(nums);
    cout << result << endl; 
    
    return 0;
}
