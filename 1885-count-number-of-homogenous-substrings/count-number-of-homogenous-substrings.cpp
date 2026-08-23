class Solution {
public:
    int countHomogenous(string s) {

        long long ans = 0;
        long long count = 0;

        for(int i = 0; i < s.size(); i++) {

            if(i > 0 && s[i] == s[i - 1])
                count++;
            else
                count = 1;

            ans += count;
        }

        return ans % 1000000007;
    }
};