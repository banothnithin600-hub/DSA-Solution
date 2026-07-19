class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        // int maxproduct = arr[0];

        // for(int i = 0; i < n; i++){
        //     int prod = 1;
        //     for(int j = i; j < n; j++){   
        //         prod *= arr[j];
        //         maxproduct = max(maxproduct, prod);
        //     }
        // }

        // return maxproduct;

        //Approach 2
        int maxprod = INT_MIN;
        int prod=1;
        for(int i=0;i<n;i++){
          prod*=arr[i];
          maxprod = max(maxprod,prod);
          if(prod==0){
            prod=1;
          }
        }
        prod = 1;
        for(int i=n-1;i>=0;i--){
            prod*=arr[i];
            maxprod = max(maxprod,prod);
            if(prod==0){
                prod=1;
            }
        }
        return maxprod;
    }
};