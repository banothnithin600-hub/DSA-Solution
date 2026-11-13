class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        
        if (len1 == 0 && len2 == 0) return 0.0;
        if (len1 == 0) {
            return len2 % 2 == 0 ? (nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2.0 : nums2[len2 / 2];
        }
        if (len2 == 0) {
            return len1 % 2 == 0 ? (nums1[len1 / 2 - 1] + nums1[len1 / 2]) / 2.0 : nums1[len1 / 2];
        }

        
        vector<int> merged(len1 + len2);
        int index1 = 0, index2 = 0, mainArrayIndex = 0;

        
        while (index1 < len1 && index2 < len2) {
            if (nums1[index1] < nums2[index2]) {
                merged[mainArrayIndex++] = nums1[index1++];
            } else {
                merged[mainArrayIndex++] = nums2[index2++];
            }
        }

        // If there are remaining elements in nums1
        while (index1 < len1) {
            merged[mainArrayIndex++] = nums1[index1++];
        }

        // If there are remaining elements in nums2
        while (index2 < len2) {
            merged[mainArrayIndex++] = nums2[index2++];
        }

        //  median
        int totalLength = len1 + len2;
        if (totalLength % 2 == 0) {
            return (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2.0;
        } else {
            return merged[totalLength / 2];
        }
    }
};
