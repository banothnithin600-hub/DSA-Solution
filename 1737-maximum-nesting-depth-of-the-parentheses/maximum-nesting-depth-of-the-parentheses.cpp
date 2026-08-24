class Solution {
public:
    int maxDepth(string s) {
        int maxl = 0;
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                maxl = max(count,maxl);
            }else if(s[i]==')'){
                 count--;
            }
        }
        return maxl;
    }
};