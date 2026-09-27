class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<pair<int,int>>rank;
        for(int num:nums){
            m[num]++;
            rank.push_back({m[num],num});
        }
        sort(rank.begin(),rank.end());
        vector<int>ans;
        for(auto& p:rank){
            ans.push_back(p.second);
        
        }
        return ans;
    }
};