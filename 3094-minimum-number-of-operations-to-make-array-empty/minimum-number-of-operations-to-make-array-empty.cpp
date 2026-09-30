class Solution {
public:
    int minOperations(vector<int>& nums) {
        int  oper = 0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
              m[nums[i]]++;
        }
        for(auto x:m){
            if(x.second==1){
                return -1;
            }
            if(x.second%3==0){
                oper+=x.second/3;
            }else{
                oper+=x.second/3+1;
            }
        }
        return oper;
    }
};