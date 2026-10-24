class Solution {
public:
    int val(int n){
        int one = 0;
        while(n>0){
            int count = n%2;
            if(count==1){
                one++;
            }
            n/=2;
        }
        return one;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        //ans[0]=0;
        for(int i=0;i<n+1;i++){
            ans.push_back(val(i));
        }
        return ans;
    }
};