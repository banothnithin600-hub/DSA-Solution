#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int solve(int i, int n, const vector<int>& costs, vector<int>& memo) {
        if (i == n) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }

        int min_cost = INT_MAX;

        // Choice 1: Jump 1 step to (i + 1)
        if (i + 1 <= n) {
            int next_cost = solve(i + 1, n, costs, memo);
            // costs is 1-indexed, so step (i + 1) maps to costs[i]
            min_cost = min(min_cost, costs[i] + 1 + next_cost);
        }

        // Choice 2: Jump 2 steps to (i + 2)
        if (i + 2 <= n) {
            int next_cost = solve(i + 2, n, costs, memo);
            min_cost = min(min_cost, costs[i + 1] + 4 + next_cost);
        }

        // Choice 3: Jump 3 steps to (i + 3)
        if (i + 3 <= n) {
            int next_cost = solve(i + 3, n, costs, memo);
            min_cost = min(min_cost, costs[i + 2] + 9 + next_cost);
        }
        return memo[i] = min_cost;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n, -1);
        return solve(0, n, costs, memo);
    }
};
