class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        int n = words.size();
        for(const string &word:words){
            if(s.substr(0,word.length())==word){
                count++;
            }
        }
        return count;
    }
};