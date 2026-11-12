class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count1= 1,count2 = 1,maxl=1,max2=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                count1++;
                maxl = max(count1,maxl);
            }else{
                count1=1;
            }
        }
        for(int i=nums.size()-1;i>0;i--){
          if(nums[i]<nums[i-1]){
            count2++;
            max2= max(max2,count2);
          }else{
            count2=1;
          }
        }
        return max({maxl,max2});
    }
};