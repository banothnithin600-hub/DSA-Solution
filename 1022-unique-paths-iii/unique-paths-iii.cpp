// class Solution { 
// public: 
//     int obstacles(vector<vector<int>>& grid, int m, int n) { 
    
//         if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size()) { 
//             return 0; 
//         } 
    
//         if (grid[m][n] == 1) return 0; 

//         if (grid[m][n] == 2) return 1; 

//         if (grid[m][n] == -1) return 0; 

        
//         return obstacles(grid, m - 1, n) + obstacles(grid, m, n - 1); 
//     } 

//     int uniquePathsIII(vector<vector<int>>& grid) { 
//         int m = grid.size(); 
//         int n = grid[0].size(); 
//         return obstacles(grid, m - 1, n - 1); 
//     } 
// };

class Solution { 
public: 
    int totalPaths = 0;
    int emptySquares = 0;

    // Added a 'count' parameter to keep track of steps taken
    void obstacles(vector<vector<int>>& grid, int m, int n, int count) { 
        // Keep your boundary checks
        if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size()) { 
            return; 
        } 
        
        // If it's an obstacle or already visited, turn back
        if (grid[m][n] == -1) return; 

        // UPDATE 3: Check if destination is reached and all empty squares are visited
        if (grid[m][n] == 2) { 
            if (count == emptySquares + 1) { // +1 accounts for starting square
                totalPaths++;
            }
            return; 
        } 

        // UPDATE 4: Temporarily mark this cell as visited (-1)
        int temp = grid[m][n];
        grid[m][n] = -1; 

        // UPDATE 2: Explore all 4 directions (Up, Down, Left, Right)
        obstacles(grid, m - 1, n, count + 1); 
        obstacles(grid, m + 1, n, count + 1); 
        obstacles(grid, m, n - 1, count + 1); 
        obstacles(grid, m, n + 1, count + 1); 

        // UPDATE 4 (Continued): Backtrack - restore the cell value
        grid[m][n] = temp;
    } 

    int uniquePathsIII(vector<vector<int>>& grid) { 
        int startM = 0, startN = 0;
        totalPaths = 0;
        emptySquares = 0;

        // UPDATE 1: Scan grid to find the '1' and count the '0's
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    emptySquares++;
                } else if (grid[i][j] == 1) {
                    startM = i;
                    startN = j;
                }
            }
        }

        // Start recursion from the actual starting point with 0 steps counted
        obstacles(grid, startM, startN, 0); 
        return totalPaths;
    } 
};
