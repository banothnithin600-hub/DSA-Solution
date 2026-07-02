class Solution { 
public: 
    int findTargetSumWays(vector<int>& arr, int target) { 
        int n = arr.size(); 
        int sum = 0; 
        for(int i = 0; i < n; i++){ 
            sum += arr[i]; 
        } 
        
        // Edge cases: target is out of bounds or sum parity matches
        if((target + sum) % 2 != 0 || abs(target) > sum) 
            return 0; 
            
        int p = (sum + target) / 2; 
        vector<long long> dp(p + 1, 0); 
        dp[0] = 1; 
        
        // Corrected 0/1 Knapsack 1D array DP transitions
        for(int k = 0; k < n; k++){ 
            for(int j = p; j >= arr[k]; j--){ 
                dp[j] += dp[j - arr[k]]; 
            } 
        } 
        return dp[p]; 
    } 
};
