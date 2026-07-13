class Solution {
public:
    long long sumAndMultiply(int n) {
        long long val = 0;
        long long sum = 0;
    vector<int>ans;
    while(n>0){
        val=n%10;
        sum+=val;
        if(val!=0){
        ans.push_back(val);
        }
        n/=10;
    }
    long long res = 0;
    for(int i=ans.size()-1;i>=0;i--){
        res=(res*10)+ans[i];
    }
    return res*sum;
    }
};