class Solution {
public:

    void bfs(vector<vector<int>>& heights,
             vector<vector<bool>>& ocean,
             queue<pair<int, int>>& q) {

        int rows = heights.size();
        int cols = heights[0].size();

        int directions[4][2] = {
            {0, 1},   // right
            {0, -1},  // left
            {1, 0},   // down
            {-1, 0}   // up
        };

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                // Outside grid
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols) {
                    continue;
                }

                // Already visited
                if (ocean[nr][nc]) {
                    continue;
                }

                // Reverse flow:
                // neighbor must be HIGHER or EQUAL
                if (heights[nr][nc] < heights[r][c]) {
                    continue;
                }

                ocean[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }


    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;


        // -----------------------------
        // 1. Pacific starting cells
        // -----------------------------

        // Top row
        for (int c = 0; c < cols; c++) {

            pacific[0][c] = true;
            pacificQueue.push({0, c});
        }

        // Left column
        for (int r = 0; r < rows; r++) {

            if (!pacific[r][0]) {
                pacific[r][0] = true;
                pacificQueue.push({r, 0});
            }
        }


        // -----------------------------
        // 2. Atlantic starting cells
        // -----------------------------

        // Bottom row
        for (int c = 0; c < cols; c++) {

            atlantic[rows - 1][c] = true;
            atlanticQueue.push({rows - 1, c});
        }

        // Right column
        for (int r = 0; r < rows; r++) {

            if (!atlantic[r][cols - 1]) {
                atlantic[r][cols - 1] = true;
                atlanticQueue.push({r, cols - 1});
            }
        }


        // -----------------------------
        // 3. BFS from Pacific
        // -----------------------------

        bfs(heights, pacific, pacificQueue);


        // -----------------------------
        // 4. BFS from Atlantic
        // -----------------------------

        bfs(heights, atlantic, atlanticQueue);


        // -----------------------------
        // 5. Find intersection
        // -----------------------------

        vector<vector<int>> answer;

        for (int r = 0; r < rows; r++) {

            for (int c = 0; c < cols; c++) {

                if (pacific[r][c] && atlantic[r][c]) {

                    answer.push_back({r, c});
                }
            }
        }

        return answer;
    }
};