#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();

    // Start from the rightmost digit
    for (int i = n - 1; i >= 0; i--) {
        // Increment the current digit
        digits[i]++;

        // If the digit becomes 10, set it to 0 and carry over the 1
        if (digits[i] == 10) {
            digits[i] = 0;
        } else {
            // If the digit is less than 10, no need to carry over, so return the digits
            return digits;
        }
    }

    // If we reach this point, it means all digits were 9s, so we need to add an additional digit 1 at the front
    digits.insert(digits.begin(), 1);

    return digits;
}

int main() {
    std::vector<int> digits = {1, 2, 3};

    std::vector<int> result = plusOne(digits);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
