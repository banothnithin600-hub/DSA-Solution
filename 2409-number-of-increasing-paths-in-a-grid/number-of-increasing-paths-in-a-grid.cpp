class Solution {
public: 
int MOD = 1e9 + 7;
    int helper(int i,int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ans = 1;
        //down
        if(i+1<n && matrix[i+1][j]>matrix[i][j]){
           ans=(ans+helper(i+1,j,n,m,matrix,dp))%MOD;
        }
        //up
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            ans=(ans+helper(i-1,j,n,m,matrix,dp))%MOD;
        }
        //right
        if(j+1<m && matrix[i][j+1]>matrix[i][j]){
            ans=(ans+helper(i,j+1,n,m,matrix,dp))%MOD;
        }
        //left
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            ans=(ans+helper(i,j-1,n,m,matrix,dp))%MOD;
        }
        dp[i][j]=ans;
        return ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long ans = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+helper(i,j,n,m,grid,dp))%MOD;
            }
        }
        return ans;
    }
};