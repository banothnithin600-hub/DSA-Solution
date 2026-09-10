class Solution {
public:
 int slidingwindowCount(vector<int>&nums,int dis){
         int i =0;
         int j =1;
         int n = nums.size();
         int paircount = 0;
         while(j<n){
            while(nums[j]-nums[i]>dis){
               i++;
            }
            paircount+=(j-i);
            j++;
         }
       return paircount;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        //brute force
    //     int n = nums.size();
    //     unoredered_set<int>ans(n);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             ans.insert(abs(nums[i]-nums[j]));
    //         }
    //     }
    //     //sort(ans.begin(),ans.end());
    //     vector<int>arr(ans.begin(),ans.end());
    //   return ans[k];

//     int n = nums.size();
//         int maxl = *max_element(nums.begin(), nums.end());
//         vector<int> arr(maxl + 1, 0);
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 int d = abs(nums[i] - nums[j]);
//                 arr[d]++; //  increment the frequency at distance d
//             }
//         }
        
//         // 4. Fix: Scan up to and including maxl, and break early when found
//         int ans = -1;
//         for(int i = 0; i <= maxl; i++){
//             k -= arr[i];
//             if(k <= 0){
//                 ans = i;
//                 break; // Stop looking once k drops below or equals 0
//             }
//         }
        
//         return ans;
    
        //Approach 2
//         int n = nums.size();
//         vector<int>ans(n*(n-1)/2);
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 ans.push_back(abs(nums[i]-nums[j]));
//             }
//         }
//        nth_element(ans.begin(),ans.end()+(k-1),ans.end());
//        return ans[k-1];
//     }
// };

//approach 3
     int n = nums.size();
      sort(nums.begin(),nums.end());
      int low = 0;
      int high = nums[n-1]-nums[0];
      int result = 0;
      while(low<=high){
        int mid = low+(high-low)/2;
        int countpair = slidingwindowCount(nums,mid);
        //mid checking count
        if(countpair<k){
            low = mid+1;
        }else{
            result = mid;
            high = mid-1;
        }
      }
      return result;
    }
   
};













