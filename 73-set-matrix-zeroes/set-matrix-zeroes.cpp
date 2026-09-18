#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();         // Number of rows
        int m = matrix[0].size();      // Number of columns
        int col0 = 1;

        // First pass to mark zeroes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {  
                    matrix[i][0] = 0; // mark row
                    if (j != 0) {
                        matrix[0][j] = 0; // mark column
                    } else {
                        col0 = 0; // first column has zero
                    }
                }
            }
        }

        // Second pass to set cells to zero
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Clear first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Clear first column if needed
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
