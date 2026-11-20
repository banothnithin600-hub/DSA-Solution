
class Solution {
public:
    int val(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            ans = ans * 2 + (s[i] - '0');
        }

        return ans;
    }

    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;

        unordered_set<int> st;
        string str = "";

        for(int right = 0; right < k; right++) {
            str += s[right];
        }

        st.insert(val(str));

        for(int right = k; right < s.length(); right++) {
            str += s[right];
            str.erase(0, 1);

            st.insert(val(str));
        }

        return st.size() == (1 << k); //2^k
    }
};
