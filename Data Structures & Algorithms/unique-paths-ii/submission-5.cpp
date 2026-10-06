class Solution {
public:

    int f(int row, int col,
          vector<vector<int>>& obstacleGrid,
          vector<vector<int>>& dp) {

        // Out of bounds
        if(row < 0 || col < 0)
            return 0;

        // Obstacle
        if(obstacleGrid[row][col] == 1)
            return 0;

        // Starting cell
        if(row == 0 && col == 0)
            return 1;

        // Already calculated
        if(dp[row][col] != -1)
            return dp[row][col];

        // Move up
        int up = f(row - 1, col, obstacleGrid, dp);

        // Move left
        int left = f(row, col - 1, obstacleGrid, dp);

        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, obstacleGrid, dp);
    }
};