class Solution {
public:
    int val(int n1,int n2){
        string str1 = to_string(n1);
        string str2 = to_string(n2);
        string str3 = str1+(str2);
        return stoi(str3);
    }
    int minMergedInteger(vector<int>& nums) {
       int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n-1;i+=2){
         int n1 = val(nums[i],nums[i+1]);
            ans.push_back(n1);
        }
        int minl = INT_MAX;
        for(int i=0;i<ans.size();i++){
           minl = min(minl,ans[i]); 
        }
        return minl;
    }
};