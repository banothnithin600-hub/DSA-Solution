class Solution {
public:
   int digit(int n){
    int val = 0;
   
    return val;
   }
    int maxProduct(int n) {
       int val = 0;
    vector<int>ans;
    while(n>0){
        val = n%10;
        ans.push_back(val);
        n/=10;
    }
    
    sort(ans.begin(),ans.end());
    int maxl = 0;
    for(int i=0;i<ans.size()-1;i++){
        maxl=max(maxl,ans[i]*ans[i+1]);
    }
      return maxl;
    }
};