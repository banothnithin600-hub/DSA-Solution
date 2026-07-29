class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> result;
        vector<int> current_permutation;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current_permutation, result);
        return result; 
    }
    private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current_permutation, vector<vector<int>>& result) {
        // Base case: A complete permutation has been formed
        if (current_permutation.size() == nums.size()) {
            result.push_back(current_permutation);
            return;
        }

        // Recursive step: Iterate through all numbers
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number has already been used
            if (used[i]) {
                continue;
            }
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }
            // Make a choice: Add the number to the current permutation
            current_permutation.push_back(nums[i]);
            used[i] = true;

            // Explore: Recurse to find the rest of the permutation
            backtrack(nums, used, current_permutation, result);

            // Backtrack: Remove the number and unmark it to explore other possibilities
            current_permutation.pop_back();
            used[i] = false;
        }
    }
}; 
