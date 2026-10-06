class Solution {
public:

    int f(int row, int col,
          vector<vector<int>>& grid,
          vector<vector<int>>& dp) {

        // Out of bounds
        if(row < 0 || col < 0)
            return 1e9;

        // Starting cell
        if(row == 0 && col == 0)
            return grid[0][0];

        // Already calculated
        if(dp[row][col] != -1)
            return dp[row][col];

        // Come from up
        int up = grid[row][col] + f(row - 1, col, grid, dp);

        // Come from left
        int left = grid[row][col] + f(row, col - 1, grid, dp);

        return dp[row][col] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, grid, dp);
    }
};