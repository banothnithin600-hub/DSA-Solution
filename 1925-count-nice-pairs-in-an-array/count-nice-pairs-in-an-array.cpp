class Solution {
public:
    int rev(int n){
        int val = 0;
        while(n>0){
           int digit = n%10;
           val = val*10+digit;
           n/=10;
        }
        return val;
    }
    int countNicePairs(vector<int>& nums) {
       int count = 0;
        int MOD = 1e9 + 7;
       unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
        int diff = nums[i]-rev(nums[i]);
         if(m.find(diff)!=m.end()){
            count=(count+m[diff])%MOD;
         }
         m[diff]++;
       }
       return count;
    }
};