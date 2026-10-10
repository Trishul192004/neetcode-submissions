
class Solution {
public:
    bool f(int i, string &s, unordered_set<string> &dict, vector<int> &dp) {
        int n = s.size();

        // Base case: entire string has been segmented successfully
        if (i == n) return true;

        // If already calculated, return the stored answer
        if (dp[i] != -1) return dp[i];

        // Try every possible prefix starting from index i
        for (int j = i; j < n; j++) {

            // Extract substring from index i to j
            string word = s.substr(i, j - i + 1);

            // If the prefix exists in the dictionary
            if (dict.find(word) != dict.end()) {

                // Check whether the remaining suffix can be segmented
                if (f(j + 1, s, dict, dp)) {
                    return dp[i] = 1;
                }
            }
        }

        // No valid partition was found
        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // Store dictionary words in a hash set for efficient lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // -1 means not calculated, 0 means false, 1 means true
        vector<int> dp(n, -1);

        return f(0, s, dict, dp);
    }
};

