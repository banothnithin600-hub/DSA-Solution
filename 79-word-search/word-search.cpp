class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>&board,string &word,int idx){
        if(idx==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j==board[0].size() || board[i][j]!=word[idx]){
            return false;
        }
        char temp = board[i][j];
         board[i][j]='/n';
        bool found = dfs(i+1,j,board,word,idx+1) || //up
                     dfs(i,j+1,board,word,idx+1) || //left
                     dfs(i-1,j,board,word,idx+1) ||  //down
                     dfs(i,j-1,board,word,idx+1);     //right
         board[i][j]=temp;
         return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(word.size()>n*m) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char val = board[i][j];
                if(val==word[0]){
                    if(dfs(i,j,board,word,0)){return true;}
                }
            }
        }
        return false;
    }
};