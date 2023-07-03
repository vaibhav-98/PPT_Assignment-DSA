#include <iostream>
#include <vector>
#include <algorithm>

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    
    // Create a 2D vector to store the minimum number of steps
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Initialize the first row and column of dp
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    
    // Fill in the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Return the minimum number of steps
    return dp[m][n];
}

int main() {
    string word1 = "sea";
    string word2 = "eat";
    int result = minDistance(word1, word2);
    cout << "Minimum number of steps: " << result << endl;
    
    return 0;
}
