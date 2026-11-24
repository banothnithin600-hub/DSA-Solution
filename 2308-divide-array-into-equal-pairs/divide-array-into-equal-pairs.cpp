class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int m1 = n/2;
        int count = 0;
        for(auto x:m){
            if(x.second%2!=0){
                return false;
            }
        }
       
        return true;
    }
};