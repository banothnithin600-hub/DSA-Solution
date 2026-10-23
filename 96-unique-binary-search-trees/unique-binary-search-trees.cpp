class Solution {
public:
    int numTrees(int n) {
        long long ans = 0;
        // for(int i=0;i<n;i++){
        //     ans = ans*(2*n-i)/(i+1);
        // }
       vector<int>dp(n+1);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
        
        //return ans/(n+1);
       // return ans;
    }
};