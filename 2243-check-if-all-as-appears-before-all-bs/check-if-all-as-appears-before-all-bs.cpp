class Solution {
public:
    bool checkString(string s) {
        bool foundA = false;
        bool foundB = false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                foundA = true;
                 if(foundB==true){ //aba
                    return false;
                 }
            }else if(s[i]=='b'){
                foundB = true;
                
            }
        }
        return true;
    }
};