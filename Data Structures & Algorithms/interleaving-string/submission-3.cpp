class Solution {
public:
    bool f(int i, int j, string &s1, string &s2,
           string &s3, vector<vector<int>> &dp) {

        // Base case: both strings are completely consumed
        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        // Check memoization
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool first = false;
        bool second = false;

        // Choice 1: Take the current character from s1
        if (i < s1.size() && s1[i] == s3[i + j]) {
            first = f(i + 1, j, s1, s2, s3, dp);
        }

        // Choice 2: Take the current character from s2
        if (j < s2.size() && s2[j] == s3[i + j]) {
            second = f(i, j + 1, s1, s2, s3, dp);
        }

        // Either choice can produce a valid interleaving
        return dp[i][j] = first || second;
    }

    bool isInterleave(string s1, string s2, string s3) {

        // Length condition
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }

        // Initialize DP table
        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return f(0, 0, s1, s2, s3, dp);
    }
};

