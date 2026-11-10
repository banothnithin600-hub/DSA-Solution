class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(const string &word : words){
            if(pref.substr(0,pref.length())==word.substr(0,pref.length())){
                count++;
            }
        }
        return count;
    }
};