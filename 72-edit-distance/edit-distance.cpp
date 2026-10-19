class Solution {
public:
    int minDistance(string word1, string word2) {
     // insert character dp[i][j-1]
     // delete character dp[i-1][j]
     // replace character dp[i-1][j-1]
        int n = word1.size();
        int m = word2.size();
        if(n==0 && m!=0) return m;
        if(n!=0 && m==0) return n;
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int j=1;j<m+1;j++){//0th row initiaze
            dp[0][j]=j;
         }
         for(int i=1;i<n+1;i++){//0th col delet
            dp[i][0]=i;
         }
         for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
               if(word1[i-1]==word2[j-1]){
                dp[i][j]=0+dp[i-1][j-1];
               }else{
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
               }
            }
         }
         return dp[n][m];
    }
};