class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product =1;
        sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
            product = (nums[n-1]-1)*(nums[n-2]-1);
        // }
        return product;
    }
};