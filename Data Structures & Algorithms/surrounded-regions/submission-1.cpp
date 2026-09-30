class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int,int>> q;

                                            // boundary regions

        // Top row
        for(int c = 0; c < cols; c++) {

            if(board[0][c] == 'O') {

                board[0][c] = '#';
                q.push({0,c});
            }
        }

        // Bottom row
        for(int c = 0; c < cols; c++) {

            if(board[rows-1][c] == 'O') {

                board[rows-1][c] = '#';
                q.push({rows-1,c});
            }
        }

        // Left col
        for(int r = 0; r < rows; r++) {

            if(board[r][0] == 'O') {

                board[r][0] = '#';
                q.push({r,0});
            }
        }

        // Right col
        for(int r = 0; r < rows; r++) {

            if(board[r][cols-1] == 'O') {

                board[r][cols-1] = '#';
                q.push({r,cols-1});
            }
        
        }




        int directions[4][2] = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };



        while(!q.empty()) {

            // Queue stores the O's that we have
            // discovered but not yet explored.
            auto [r,c] = q.front();
            q.pop();

            for(auto &dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                // Outside the board
                if(nr < 0 || nr >= rows ||
                   nc < 0 || nc >= cols) {
                    continue;
                }

                // Only process O's
                if(board[nr][nc] != 'O')
                    continue;

                // Mark as safe
                board[nr][nc] = '#';

                q.push({nr,nc});
            }
        }


        // capture remaining O's
        for(int r = 0; r < rows; r++) {

            for(int c = 0; c < cols; c++) {

                // Surrounded region
                if(board[r][c] == 'O')
                    board[r][c] = 'X';

                // Safe region
                else if(board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};