class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Put all treasure chests into the queue
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {

                if(grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }

        // 4 directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Multi-source BFS
        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // Check boundaries
                if(newRow < 0 || newRow >= m ||
                   newCol < 0 || newCol >= n) {
                    continue;
                }

                // Skip water and already visited cells
                if(grid[newRow][newCol] != INT_MAX) {
                    continue;
                }

                // Set shortest distance
                grid[newRow][newCol] = grid[row][col] + 1;

                // Add to queue
                q.push({newRow, newCol});
            }
        }
    }
};