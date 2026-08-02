class Solution {
public:
   
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
         int even = 0;
         int odd = 0;
         for(int j=i;j<n;j++){
            if(nums[j]%2==0){
                even++;
            }else{
                odd++;
            }
            if(((double)even/(double)odd)<=((double)a/(double)b)){
                count++;
            }
         }
        }
        return count;
    }
};