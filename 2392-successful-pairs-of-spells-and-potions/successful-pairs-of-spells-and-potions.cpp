// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int n = potions.size();
//         int m = spells.size();
//         vector<int>ans;
//         long long idx = 0;
//         while(m--){
//             long long  count = 0;
//         for(int i=0;i<n;i++){
//              long long val = (long long)potions[i]*spells[idx];
//              if(val>=success){
//                 count++;
//              }
//         }
//         ans.push_back(count);
//         idx++;
//       }
//        return ans;
//     }
// };

class Solution {
public:
    int product(int val, vector<int> &arr, long long succ){

        int left = 0, right = arr.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;

            long long prod = 1LL * val * arr[mid];
            if(prod >= succ){
                right = mid-1;
            }else{
                left = mid + 1; 
            }
        }
        return arr.size() - left;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;

        sort(potions.begin(), potions.end());
        
        for(int i = 0; i < spells.size(); i++){
            int pair = product(spells[i], potions, success);
            ans.push_back(pair);
        }

        return ans;
    }
};