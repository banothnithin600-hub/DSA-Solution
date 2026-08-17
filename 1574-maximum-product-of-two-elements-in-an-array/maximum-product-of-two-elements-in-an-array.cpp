class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        //Approach 1
        // int product =1;
        // sort(nums.begin(),nums.end());
        // // for(int i=0;i<n;i++){
        //     product = (nums[n-1]-1)*(nums[n-2]-1);
        // // }
        // return product;

        //Approach 2
         priority_queue<int,vector<int>,greater<int>>pq;
         for(int i=0;i<n;i++){
            pq.push(nums[i]);
         }

         //while(pq.size()>=2){
           while(pq.size()>2){
            pq.pop();
           }
         //}
         int v1 = pq.top(); pq.pop();
         int v2 = pq.top();  pq.pop();
         return (v2-1)*(v1-1);
    }
};