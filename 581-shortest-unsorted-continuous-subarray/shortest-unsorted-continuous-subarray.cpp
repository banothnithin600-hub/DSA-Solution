class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = -1;
        int maxl = nums[0],minl = nums[n-1];
        for(int i=1;i<n;i++){
            if(nums[i]<maxl){
                 left = i;
            }else{
                maxl = nums[i];
            }
        }
        for(int i=n-2;i>=0;i--){
           
            if(nums[i]>minl){
                right = i;
            }else{
                minl = nums[i];
            }
        }
        if(left==-1) return 0;
        return left-right+1;
    }
};