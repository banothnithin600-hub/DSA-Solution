#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Min-heap stores pairs: {soldier_count, row_index}
        // It automatically sorts by count first, then by index if counts are equal
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    count++;
                } else {
                    break; // Since 1s always appear before 0s, we can stop early
                }
            }
            pq.push({count, i});
        }
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second); // Get the row index
            pq.pop();
        }
        
        return ans;
    }
};
