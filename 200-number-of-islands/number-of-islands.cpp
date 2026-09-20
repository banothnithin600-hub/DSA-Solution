class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m ||  grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';//already vistied 1 in island
        dfs(grid,i+1,j,n,m);//down
        dfs(grid,i-1,j,n,m);//up
        dfs(grid,i,j+1,n,m);//right
        dfs(grid,i,j-1,n,m);//left
    }
    int numIslands(vector<vector<char>>& grid) {
        int V = grid.size();
      //vector<vector<int>>adj(V);
      int count = 0;
      vector<bool>vis(V,false);
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                if(!vis[i]){
               dfs(grid,i,j,grid.size(),grid[0].size());
               count++;
                }
            }
          }
      }
      return count;
    }
};