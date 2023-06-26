#include <iostream>
using namespace std;
#include <vector>

bool isMonotonic(vector<int>& nums) {
    bool isIncreasing = true;
    bool isDecreasing = true;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            isDecreasing = false;
        }
        
        if (nums[i] < nums[i - 1]) {
            isIncreasing = false;
        }
    }
    
    return isIncreasing || isDecreasing;
}



int main() {
    vector<int> nums = {1, 2, 2, 3};
    bool result = isMonotonic(nums);
    cout << boolalpha << result << endl;
    
    return 0;
}



//