#include <vector>

using namespace std;

class Solution {
public:
    // Performs DFS to calculate the total sum of cell values for the current island
    long long dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        // Base case: Out of bounds or water cell (0)
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }
        
        // Add the current cell's value to the island's total sum
        long long current_value = grid[i][j];
        
        // Mark the current cell as visited by setting it to water (0)
        grid[i][j] = 0;
        
        // Traverse all 4 adjacent directions and accumulate the values
        current_value += dfs(i - 1, j, grid, n, m); // Up
        current_value += dfs(i + 1, j, grid, n, m); // Down
        current_value += dfs(i, j - 1, grid, n, m); // Left
        current_value += dfs(i, j + 1, grid, n, m); // Right
        
        return current_value;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // An island's land cell can contain any positive integer, not just 1
                if (grid[i][j] > 0) {
                    long long totalValue = dfs(i, j, grid, n, m);
                    
                    // Check if the total sum value of the island is divisible by k
                    if (totalValue % k == 0) {
                        islandCount++;
                    }
                }
            }
        }
        return islandCount;
    }
};
