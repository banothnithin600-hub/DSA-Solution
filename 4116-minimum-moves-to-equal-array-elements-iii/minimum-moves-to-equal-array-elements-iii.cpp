class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans =0;
        int m = -1;
        for(auto el: nums) m = max(el,m);
        for(auto el: nums){
            ans += (m-el);
        }
        return ans;
    }
};