class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, bool& closed) {
        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        // Already visited / water
        if (grid[r][c] == 1)
            return;

        // If island touches boundary, it is not closed
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
            closed = false;

        // Mark visited
        grid[r][c] = 1;

        // 4 directions
        dfs(r - 1, c, grid, closed);
        dfs(r + 1, c, grid, closed);
        dfs(r, c - 1, grid, closed);
        dfs(r, c + 1, grid, closed);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {

                    bool closed = true;

                    dfs(i, j, grid, closed);

                    if (closed)
                        count++;
                }
            }
        }

        return count;
    }
};