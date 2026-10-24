class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                 count++;
                 ans=ans+count;
            }else{
                count=0;
            }
        }
        return ans;
    }
};