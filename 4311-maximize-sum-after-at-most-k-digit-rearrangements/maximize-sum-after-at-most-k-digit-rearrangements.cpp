class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long totalsum = 0;
        vector<int>&new1 = nums;
        reverse(new1.begin(),new1.end());
        for(int& num: new1){
            totalsum +=num;
            string s = to_string(num);
            sort(s.begin(),s.end(),greater<char>());
            num = stoi(s)-num;
        }
        int op = min(k,(int)new1.size());
        nth_element(new1.begin(),new1.begin()+op-1,new1.end(),greater<int>());
        for(int i=0;i<op;i++){
            if(new1[i]>0){
            totalsum+=new1[i];
            }
        }
        return totalsum;
    }
};