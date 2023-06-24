#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort the array in ascending order
    int max_sum = 0;
    
    
    for (int i = 0; i < nums.size(); i += 2) {
        max_sum += nums[i];
    }
    
    return max_sum;
}




int main() {
    vector<int> nums = {1, 4, 3, 2};
    int result = arrayPairSum(nums);
    cout << result << endl; 
    
    return 0;
}
