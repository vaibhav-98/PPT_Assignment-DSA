#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort the array in ascending order
    
    int n = nums.size();
    
    // Calculate two possible products
    int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3]; 
    int product2 = nums[0] * nums[1] * nums[n - 1]; 
    
    return max(product1, product2);
}



int main() {
    vector<int> nums = {1, 2, 3};
    int result = maximumProduct(nums);
    cout << result << endl; 
    
    return 0;
}
