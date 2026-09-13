class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
       long long int sum =0;
       long long int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};