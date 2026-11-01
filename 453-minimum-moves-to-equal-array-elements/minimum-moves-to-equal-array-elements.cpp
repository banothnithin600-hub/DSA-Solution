class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        // unordered_map<int,int>m;
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        // }
        // for(auto x:m){
        //     if(x.first==1) return m.size()-1;
            
        // }
        // return 0;
        int minl = INT_MAX,sum=0,value=0;
        for(int i=0;i<n;i++){
            minl = min(minl,nums[i]);
        }
            //sum+=nums[i];
        for(int i=0;i<n;i++){
            value+=nums[i]-minl;
        }
        return value;
    }
};