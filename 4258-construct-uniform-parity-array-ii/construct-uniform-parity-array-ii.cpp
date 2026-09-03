class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minodd = INT_MIN;
        bool oddcount =0;
        for(int x:nums1){
            if(x%2!=0){
                oddcount=true;
                minodd=min(minodd,x);
            }
        }
            // if(oddcount==0 || oddcount==n){
            //     return true;
            // }
         if(!oddcount) return true;
            int minval = *min_element(nums1.begin(),nums1.end());
            if(minval%2==0){
                return oddcount>=2;
            }
            else
                return true;
        for(int x:nums1){
            if(x%2==0 && x<=minodd){
                return false;
            }
        }
         return true;
    }
};