class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid= nums[n/2];
        long long count = 0;
        for(int i=0;i<n;i++){
         if(mid==nums[i]){
            count++;
         }
        }
        if(count!=1){
            return false;
        }
        return true;
    }
};