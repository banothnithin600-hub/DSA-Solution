class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
    //    int maxi = 0;

    //     for(int i = 0; i<nums.size(); i++) {
    //         maxi = max(maxi , nums[i]);
    //         int mini = INT_MAX;

    //         for(int j = i; j<nums.size(); j++) {
    //             mini = min(mini , nums[j]);
    //         }
            
    //         if(maxi - mini <= k) {
    //             return i;
    //         }
    //     }
    //     return -1;
     int n = nums.size();
      vector<int>mx(n);
      //prefix
      int maxl = INT_MIN;
      for(int i=0;i<n;i++){
        maxl = max(maxl,nums[i]);
        mx[i]=maxl;
      }
      //suffix
      vector<int>mn(n);
      int minl = INT_MAX;
      for(int i=n-1;i>=0;i--){
        minl=min(minl,nums[i]);
        mn[i]=minl;
      }
      for(int i=0;i<n;i++){
        if(abs(mn[i]-mx[i])<=k){
            return i;
        }
      }
      return -1;
    }
};