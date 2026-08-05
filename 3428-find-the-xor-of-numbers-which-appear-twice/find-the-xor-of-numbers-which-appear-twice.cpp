class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int xorr=0;
        for(int i=0;i<nums.size();i++){
            if(i<(nums.size()-1) && (nums[i]==nums[i+1])){
            xorr^=nums[i];
        }
        }
        return xorr;
    }
};