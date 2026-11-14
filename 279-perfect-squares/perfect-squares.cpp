class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==0) return 0;
        int ans = INT_MAX;
        if(dp[n]!=-1) return dp[n];
       for(int i=1;i*i<=n;i++){
        ans=min(ans,1+f(n-(i*i),dp));
       }
       dp[n]=ans;
       return dp[n];
    }
    int numSquares(int n) {
       //1 4 9 16 are perfect square 
       // 3 and 11 are not
       vector<int>dp(n+1,-1);
    return f(n,dp);
    }
};