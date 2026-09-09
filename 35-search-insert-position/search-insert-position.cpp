class Solution {
public:
    int searchInsert(vector<int>& nums, int key) {
        int start = 0;
        int end = nums.size() - 1;
        while (start<=end){
            int mid = end + (start - end) / 2;
            if(nums[mid]==key)
            return mid;
            else if(nums[mid]<key)
            start = mid +1;
            else end = mid - 1;
        }
        return start;
    }
};