class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0;
        int maxl = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                count++;
                maxl=max(maxl,count);
            }else{
                count=0;
            }
        }
        return maxl+1;
    }
};