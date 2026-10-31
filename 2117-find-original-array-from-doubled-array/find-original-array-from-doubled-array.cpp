class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        if(arr.size()==0 || arr.size()==1) return {};
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
             m[arr[i]]++;
        }
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]==0){
                continue;
            }
            if(m[arr[i]*2]==0){
                return {};
            }
             if (arr[i] == 0 && m[arr[0]] < 2) {
                return {}; 
            }
            ans.push_back(arr[i]);
            m[arr[i]]--;
            m[arr[i]*2]--;
        }
        return ans;
    }
};