class Solution {
public:
    int ways(string& str, int idx, vector<int>& dp) {
        if (idx == str.length()) return 1;
        if (str[idx] == '0') return 0;

        if (dp[idx] != -1) return dp[idx];

        int v1 = ways(str, idx + 1, dp);

        if (idx + 1 < str.length() &&
            (str[idx] == '1' ||
            (str[idx] == '2' && str[idx + 1] <= '6'))) {
            v1 += ways(str, idx + 2, dp);
        }

        return dp[idx] = v1;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return ways(s, 0, dp);
    }
};