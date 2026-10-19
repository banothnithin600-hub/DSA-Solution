class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=n || j>=m){
            return 0;
        }
        int ans = 1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
          // Moving Down (i+1)
        if(i+1 < n && matrix[i+1][j] > matrix[i][j]){ 
            ans=max(ans,1+helper(i+1,j,n,m,matrix,dp));
         }
        // Moving Up (i-1)
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]){ 
            ans=max(ans,1+helper(i-1,j,n,m,matrix,dp)); 
        }
        // Moving Right (j+1)
        if(j+1 < m && matrix[i][j+1] > matrix[i][j]){ 
            ans=max(ans,1+helper(i,j+1,n,m,matrix,dp));
         }
        // Moving Left (j-1)
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]){ 
            ans=max(ans,1+helper(i,j-1,n,m,matrix,dp));
        }
        dp[i][j]=ans;
        return ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,helper(i,j,n,m,matrix,dp));
            }
        }
        return ans;
    }
};