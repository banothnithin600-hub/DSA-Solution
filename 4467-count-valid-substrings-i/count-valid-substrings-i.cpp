class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.length();
        long long ans = 0;
        int val = -1;
        for(int i=0;i<n;i++){
            if(i>=2 && s[i-2]=='a' && s[i-1]=='b' && s[i]=='c') val = i-2;
            ans +=(i-val);
        }
        return ans;
    }
};