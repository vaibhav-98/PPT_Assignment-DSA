#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> numSet;

    for (int num : nums) {
        // If the current number is already in the set, it's a duplicate
        if (numSet.count(num) > 0) {
            return true;
        }
        // Otherwise, add the number to the set
        numSet.insert(num);
    }

    // No duplicates found
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1};

    bool result = containsDuplicate(nums);

    std::cout << "Output: " << std::boolalpha << result << std::endl;

    return 0;
}
