class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //step by step approach 
        //step 1: sorting the array 
        //step2: a,b were take the last two number and c,d were take first two number 
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return ((nums[n-1]*nums[n-2])-(nums[0]*nums[1]));
    }
};