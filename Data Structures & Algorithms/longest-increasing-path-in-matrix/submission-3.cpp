
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix,
          vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Return the stored answer if already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // The current cell itself forms a path of length 1
        int maxi = 1;

        // Four possible directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            // Check whether the neighbor is inside the matrix
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {

                // Move only to a strictly greater value
                if (matrix[ni][nj] > matrix[i][j]) {
                    int len = 1 + f(ni, nj, matrix, dp);
                    maxi = max(maxi, len);
                }
            }
        }

        // Store and return the longest path starting from this cell
        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();

        if (n == 0 || matrix[0].empty()) {
            return 0;
        }

        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        // Try starting the path from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, f(i, j, matrix, dp));
            }
        }

        return ans;
    }
};

