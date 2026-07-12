class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
        // Step 1: Store values with their original indices
        vector<pair<int, int>> mp(n);
        for(int i = 0; i < n; i++) {
            mp[i] = {arr[i], i};
        }
        
        // Step 2: Sort the array of pairs
        sort(mp.begin(), mp.end());
        
        vector<int> rank_vec(n);
        int rank = 1;
        
        // The smallest element always gets rank 1
        rank_vec[mp[0].second] = rank;
        
        // Step 3: Assign ranks to the rest
        for(int i = 1; i < n; i++) {
            // Increment rank ONLY if current value is strictly greater
            if(mp[i].first > mp[i-1].first) {
                rank++;
            }
            rank_vec[mp[i].second] = rank;
        }
        
        return rank_vec;
    }
};