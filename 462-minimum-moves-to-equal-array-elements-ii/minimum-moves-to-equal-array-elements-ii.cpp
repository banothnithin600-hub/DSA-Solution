class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        long long step=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
         int median=nums[n/2];
         step+=abs(median-nums[i]);  //we can write even and odd tream in array
        }
        return step;
    }
};