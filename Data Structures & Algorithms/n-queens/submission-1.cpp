class Solution {
public:

    bool issafe(int row, int col, int n, vector<string>& board) {

        int duprow = row;
        int dupcol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }

            row--;
            col--;
        }

        // Reset row and col
        row = duprow;
        col = dupcol;

        // Check left side of the same row
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }

            col--;
        }

        // Reset row and col
        row = duprow;
        col = dupcol;

        // Check lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }

            row++;
            col--;
        }


        return true;
    }


    void solve(int col,
               vector<string>& board,
               vector<vector<string>>& ans,
               int n) {

        // All columns have been filled
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every row of current column
        for (int row = 0; row < n; row++) {

            if (issafe(row, col, n, board)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                solve(col + 1, board, ans, n);

                // Undo / Backtrack
                board[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Board should be vector<string>, not vector<vector<string>>
        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};