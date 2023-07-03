#include <iostream>
#include <vector>

using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D vector to store the minimum ASCII sum of deleted characters
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and column
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    // Fill in the remaining cells of the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters are equal, no deletion required
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Characters are not equal, choose the minimum of deleting from s1 or s2
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    // Return the lowest ASCII sum of deleted characters
    return dp[m][n];
}

int main() {
    string s1 = "sea";
    string s2 = "eat";
    int result = minimumDeleteSum(s1, s2);
    cout << "Lowest ASCII sum of deleted characters: " << result << endl;
    return 0;
}
