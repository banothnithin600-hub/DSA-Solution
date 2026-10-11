class Solution {
public:
    int val(int n){
       // int m = n.size();
        int count = 0;
        while(n>0){
            int v = n%10;
           count++;
            n/=10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<nums.size();i++){
           if(val(nums[i])%2==0){
            count++;
           }
        }
        return count;
    }
};