class Solution {
public:
     int digit(int n){
        int sum = 0;
        while(n>0){
           int val=n%10;
            sum+=val;
            n/=10;
        }
        return sum;
     }
    int smallestIndex(vector<int>& nums) {
        int val = -1;
        for(int i=0;i<nums.size();i++){
           if(digit(nums[i])==i){
               val=i;
               break;
           }
        }
        return val;
    }
};