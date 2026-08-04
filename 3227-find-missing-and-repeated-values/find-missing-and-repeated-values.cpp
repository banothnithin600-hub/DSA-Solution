class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans.push_back(grid[i][j]);
            }
        }

        vector<int> count(n * n + 1, 0);  // FIXED
        int duplicate = -1, missing = -1;

        for (int x : ans) {
            count[x]++;
        }

        for (int i = 1; i <= n * n; i++) {  // better to use n*n
            if (count[i] == 2) {
                duplicate = i;
            } else if (count[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};