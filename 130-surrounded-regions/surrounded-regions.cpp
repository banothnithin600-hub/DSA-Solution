class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m ||
            board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'S';

        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Step 1: Start DFS only from boundary O's

        // First and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[n - 1][j] == 'O')
                dfs(board, n - 1, j);
        }

        // First and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        // Step 2: Remaining O -> X
        // Step 3: Safe S -> O

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};
// 1. Find all boundary O's → mark them SAFE 
// 2. Find all O's that are not SAFE → convert them to X
// 3. Convert SAFE back to O
// 4. Return matrix