class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        // Create a frequency array to count occurrences of numbers 1 to n
        vector<int> count(n + 1, 0); 
        int duplicate = -1, missing = -1;

        // Step 1: Fill the frequency array
        for (int x : nums) {
            count[x]++;
        }

        // Step 2: Find the duplicate (count == 2) and missing (count == 0)
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                duplicate = i;
            } else if (count[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};
