class Solution {
public:
    int kthFactor(int n, int k) {
        if(n==0 || k==0) return 0;
        if(n==1 && k==1) return 1;
       // if(k==n) return -1;
        vector<int>ans;
        int count = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0)
            ans.push_back(i);
        }
        int m = ans.size();
        // for(int i=0;i<m;i++){
        //     if(ans[i]%k==0) count++;
        //     // else{
        //     //      count++;
        //     // }
        // }
        if (ans.size() < k)
            return -1;
        return ans[k-1];
    }
};