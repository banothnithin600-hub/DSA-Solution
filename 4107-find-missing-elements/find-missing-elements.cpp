class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
       int s = nums[0];
       int e = nums[n-1];
        // int idx=0;
        // for(int i=s;i<=e;i++){
        //  if(i!=nums[idx]){
        //    ans.push_back(i);
        //    idx++;
        //  }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(int i=s;i<=e;i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
            }
        }
    
        return ans;
    }
};