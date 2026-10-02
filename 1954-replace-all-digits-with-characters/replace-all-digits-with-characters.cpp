class Solution {
public:
    string replaceDigits(string s) {
        int n = s.length();
        for(int i=1;i<=n;i++){
            if(isdigit(s[i])){
                s[i]= (s[i]-'0'+s[i-1]);
            }
        }
        return s;
    }
};