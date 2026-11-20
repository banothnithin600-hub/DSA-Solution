class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int  n = nums.size();
        unordered_set<int>s;
      long long int sum = 0;
      long long max_sum = 0;
      int left = 0;
        for(int right=0;right<n;right++){
             if(s.find(nums[right])==s.end()){
                s.insert(nums[right]);
                sum+=nums[right];
                if(right-left+1==k){
                    max_sum = max(max_sum,sum);
                    sum-=nums[left];
                    s.erase(nums[left]);
                    left++;
                }
             }
             else{
                while(nums[left]!=nums[right]){
                    sum-=nums[left];
                    s.erase(nums[left]);
                    left++;
                }
                left++;
             }
        }
        return max_sum;
    }
};