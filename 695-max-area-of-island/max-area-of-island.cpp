class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==2 || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=2;//already vistied 1 in island
        int cur_size = 1+dfs(grid,i+1,j,n,m)
                        +dfs(grid,i-1,j,n,m)
                        +dfs(grid,i,j+1,n,m)
                        +dfs(grid,i,j-1,n,m);
        return cur_size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxl = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxl = max(maxl,dfs(grid,i,j,n,m));
            }
        }
        return maxl;
    }
};