class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d) {

        for (int i = 0; i < 9; i++) {
            if ( board[row][i] == d)
                return false; // column
            if ( board[i][col] == d)
                return false; // row
        }

        int start_i = row/3 * 3;
        int col_i = col/3 * 3;

        for(int k = 0; k<3; k++){
            for(int l = 0; l<3; l++){
                if(board[start_i+k][col_i+l] == d) return false;
            }
        }

        return true;
    }

    bool sol(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char d = '1'; d<='9'; d++){

                        if(isValid(board,i,j,d)){
                            board[i][j] = d;
                        
                        if(sol(board)) return true;
                        board[i][j] = '.'; 
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {

        sol(board);

    }
};