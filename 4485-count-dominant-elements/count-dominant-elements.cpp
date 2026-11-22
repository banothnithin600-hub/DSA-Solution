class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if(n==1) return 1;
        if(nums[0]>=nums[1]){
            count++;
        }
         if(nums[n-1]>=nums[n-2]){
            count++;
        }
      double avg = 0;
       // int sum = 0;
        for(int i=1;i<n-1;i++){
           avg = (nums[i-1]+nums[i+1])/2.0;
           if(nums[i]>=avg){
            count++;
           }
        }
       
        return count;
    }
};