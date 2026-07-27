class Solution {
public:
    string longestNiceSubstring(string s) {
        //base case
        if(s.size()<2) return "";
        int n = s.size();
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        for(int i=0;i<n;i++){
            if(st.count(tolower(s[i])) && st.count(toupper(s[i]))) continue;
           string left = longestNiceSubstring(s.substr(0,i));
           string right =  longestNiceSubstring(s.substr(i+1));
            return left.size()>=right.size()?left:right;
        }
        return s;
    }
};