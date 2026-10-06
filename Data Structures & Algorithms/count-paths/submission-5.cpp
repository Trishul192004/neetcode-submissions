class Solution {
public:
    int f(int m ,int n , vector<vector<int>>&dp){
        if( m == 1 || n == 1 ) return 1;
        if(dp[m][n] != -1) return dp[m][n];

        int down = f(m-1 ,n,dp); // row size dec as going down
        int right = f(m,n-1,dp);

        return dp[m][n] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,dp);
    }
};
