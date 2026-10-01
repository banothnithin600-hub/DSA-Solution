class Solution {
public:
    int val2(vector<int>nums){//last
        int n = nums.size();
        nums[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
          nums[i]=max(nums[i]+nums[i-2],nums[i-1]);
        }
        return nums[n-2];
    }
    int val1(vector<int>nums){//first
        int n = nums.size();
        nums[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            nums[i]=max(nums[i]+nums[i-2],nums[i-1]);
        }
        return nums[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(val1(nums),val2(nums));
    }
};