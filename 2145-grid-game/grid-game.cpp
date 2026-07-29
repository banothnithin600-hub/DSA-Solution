
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top = 0;
        for(int i=0;i<n;i++){
        top+=grid[0][i];
        }
        long long bottom = 0, res=LLONG_MAX;
        for(int i=0;i<n;i++){
         top-=grid[0][i];
         res=min(res,max(bottom,top));
         bottom+=grid[1][i];
        }
        return res;
    }
};