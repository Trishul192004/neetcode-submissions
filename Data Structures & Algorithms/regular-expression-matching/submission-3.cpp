class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

        if(i < 0 && j < 0) return true;

        if(j < 0) return false;

        // FIX: Handle an exhausted string
        if(i < 0) {
            if(p[j] == '*') {
                return f(i, j-2, s, p, dp);
            }
            return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // Handle '*'
        if(p[j] == '*') {
            bool zero = f(i, j-2, s, p, dp);

            bool one = false;

            if(p[j-1] == s[i] || p[j-1] == '.') {
                one = f(i-1, j, s, p, dp);
            }

            return dp[i][j] = zero || one;
        }

        // Handle matching characters and '.'
        if(s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, s, p, dp);
    }
};