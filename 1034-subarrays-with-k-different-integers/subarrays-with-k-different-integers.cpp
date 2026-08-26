
class Solution {
public:
    // Helper function to count subarrays with AT MOST k distinct integers
    int countAtMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int n = nums.size();
        int left = 0, count = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; right++) {
            // Add current element to frequency map
            freq[nums[right]]++;

            // Shrink window if unique elements exceed k
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // All subarrays ending at 'right' starting from 'left' to 'right' are valid
            count += (right - left + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly K = AtMost(K) - AtMost(K - 1)
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }
};
