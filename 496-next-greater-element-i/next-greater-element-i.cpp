class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result(n, -1); // Initialize results vector with -1
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // When equal, start looking for the next greater element
                if (nums1[i] == nums2[j]) {
                    // Loop forward to find the next greater element
                    for (int k = j + 1; k < m; k++) {
                        if (nums2[k] > nums2[j]) { // found the next greater element
                            result[i] = nums2[k];
                            break; // Stop searching once found
                        }
                    }
                    break; // Break out of the outer loop once found
                }
            }
        }
        return result; // Return the result vector
    }
};
