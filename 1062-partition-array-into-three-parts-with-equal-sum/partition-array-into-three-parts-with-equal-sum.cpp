class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int totalsum = 0;
        if(n<3) return false;
        for(int i=0;i<n;i++){
          totalsum+=arr[i];
        }
        if(totalsum%3!=0){
            return false;
        }
        int k = totalsum/3;
        int count = 0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                sum=0;
                count++;
            }
        }
        return count>=3;
    }
};