class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //brute force
    //     int n = nums.size();
    //     unoredered_set<int>ans(n);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             ans.insert(abs(nums[i]-nums[j]));
    //         }
    //     }
    //     //sort(ans.begin(),ans.end());
    //     vector<int>arr(ans.begin(),ans.end());
    //   return ans[k];

    int n = nums.size();
        int maxl = *max_element(nums.begin(), nums.end());
        vector<int> arr(maxl + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int d = abs(nums[i] - nums[j]);
                arr[d]++; // Fix: increment the frequency at distance d
            }
        }
        
        // 4. Fix: Scan up to and including maxl, and break early when found
        int ans = -1;
        for(int i = 0; i <= maxl; i++){
            k -= arr[i];
            if(k <= 0){
                ans = i;
                break; // Fix: Stop looking once k drops below or equals 0
            }
        }
        
        return ans;
    }
};