class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        long long int n = nums.size();
    //    int maxl = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(abs(j-i)>=k){
    //                 maxl=max(maxl,nums[i]+nums[j]);
    //             }
    //         }
    //     }
    //     return maxl;

    int ans = INT_MIN,left = INT_MIN;
    for(int i=k;i<n;++i){
        left=max(left,nums[i-k]);
        ans=max(ans,left+nums[i]);
    }
    return ans;
    }
};