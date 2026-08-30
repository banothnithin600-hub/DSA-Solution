class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minind = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxind = max_element(nums.begin(), nums.end()) - nums.begin();
        // Make minind the smaller index
        if(minind > maxind) swap(minind, maxind);
        int ans = min({
            maxind + 1,              // delete from front
            n - minind,              // delete from back
            minind + 1 + n - maxind  // delete from both sides
        });
        return ans;
    }
};