#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to check if placing a queen is safe
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check vertical column up
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    
    int solve(int row, vector<string>& board, int n) {
        // Base case: All queens are placed successfully
        if (row == n) {
            return 1;
        }

        int count = 0;

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // Place queen
                
                count += solve(row + 1, board, n); 
                
                board[row][col] = '.'; // Backtrack (remove queen)
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = solve(0, board, n);
        return count;
    }
};
