class NumArray {
public:
    // This array will store the running sums (prefix sums)
    vector<int> pre;

    // Constructor: runs ONE time at the start
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre.resize(n + 1);        // pre has one extra place
        pre[0] = 0;               // before any number, sum is 0

        // Build prefix sums
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
            // pre[i+1] = sum of nums[0] to nums[i]
        }
    }

    // sumRange(left, right) = nums[left] + ... + nums[right]
    int sumRange(int left, int right) {
        // use the trick: sum = pre[right+1] - pre[left]
        return pre[right + 1] - pre[left];
    }
};
