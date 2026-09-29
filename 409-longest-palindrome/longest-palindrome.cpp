class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            if(m[s[i]]&1){
                count++;
            }else{
                count--;
            }
        }
        if(count>1){
            return s.length()-count+1;
        }
        return s.length();
    }
};