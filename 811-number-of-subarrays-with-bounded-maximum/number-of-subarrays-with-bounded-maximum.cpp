class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0,heads = 0,tails =0;
        for(int val:nums){
            if(left<=val && val<=right){
                heads+=tails+1;
                tails=0;
                res+=heads;
            }else if(val<left){
                tails++;
                res+=heads;
            }else{
                heads = 0;
                tails = 0;
            }
        }
        return res;
    }
};