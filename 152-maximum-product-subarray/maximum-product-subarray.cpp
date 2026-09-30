// class Solution {
// public:
//     int prefix(vector<int>&arr,int maxproduct,int i){
//         if(i==n-1){
//             return maxproduct;
//         }
//         if(maxproduct>=0) maxproduct = 1;
//         return prefix(arr[i]*maxproduct,max(maxproduct,arr[i]*maxproduct),i+1);
//     }
//     int suffix(vector<int>&arr.int maxprod,int n){
//         if(n==0){
//             return maxprod;
//         }
//         if(maxprod>=0) maxprod = 1;
//         return suffix(arr[n-1]*maxprod,max(maxprod,arr[n-1]*maxprod),n-1);
//     }
//     int maxProduct(vector<int>& arr) {
//         int n = arr.size();
//         // int maxproduct = arr[0];

//         // for(int i = 0; i < n; i++){
//         //     int prod = 1;
//         //     for(int j = i; j < n; j++){   
//         //         prod *= arr[j];
//         //         maxproduct = max(maxproduct, prod);
//         //     }
//         // }

//         // return maxproduct;

//         //Approach 2
//         int maxprod = INT_MIN;
//         int prod=1;
//         for(int i=0;i<n;i++){
//           prod*=arr[i];
//           maxprod = max(maxprod,prod);
//           if(prod==0){
//             prod=1;
//           }
//         }
//         prod = 1;
//         for(int i=n-1;i>=0;i--){
//             prod*=arr[i];
//             maxprod = max(maxprod,prod);
//             if(prod==0){
//                 prod=1;
//             }
//         }
//         return maxprod;
//     }
// };
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProduct(std::vector<int>& arr) {
        int n = arr.size();
        int max_prod = INT_MIN;
        
        int prefix = 1;
        int suffix = 1;
        
        for (int i = 0; i < n; i++) {
            // If prefix or suffix becomes 0, reset it to 1
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            
            // Calculate prefix from left to right
            prefix *= arr[i];
            
            // Calculate suffix from right to left
            suffix *= arr[n - 1 - i];
            
            // Track the maximum value seen so far
            max_prod = std::max({max_prod, prefix, suffix});
        }
        
        return max_prod;
    }
};
