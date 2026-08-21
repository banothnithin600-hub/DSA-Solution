class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(auto str: strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            m[temp].push_back(str);
        }
        vector<vector<string>>ans;
        for(pair<string,vector<string>> i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};