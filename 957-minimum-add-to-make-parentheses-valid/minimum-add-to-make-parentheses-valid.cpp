class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                close++;
            }else{
                if(close>0){//matched with this )
                    close--;
                }else{   // close is zero py is no ( then we are count open:- )
                  open++;
                }
            }
        }
        return open+close;
    }
};