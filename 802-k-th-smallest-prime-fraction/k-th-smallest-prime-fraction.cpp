class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();

        priority_queue<pair<double, pair<int,int>>> pq;

        // Generate all fractions
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                
                double fraction = (double)arr[i] / arr[j];

                pq.push({fraction, {arr[i], arr[j]}});

                // Keep only k smallest fractions
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }

        auto ans = pq.top();

        return {ans.second.first, ans.second.second};
    }
};