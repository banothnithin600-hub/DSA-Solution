class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long maxlength = 0;
        long long prefixSum = k;
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            long long len = right - left +1;
            long long target = nums[right]*len;
            prefixSum +=nums[right];
            while(left<right && prefixSum<target){
                prefixSum -=nums[left++];
                len = right-left+1;
                target = nums[right]*len;
            }
            maxlength = max(len,maxlength);
        }
        return maxlength;
    }
};