// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//     // Brtue force
//     // long long int count=0;
//     //   for(int i=0;i<nums.size()-1;i++){
//     //     for(int j=i+1;j<nums.size();j++){
//     //         if(nums[i]>(long long)2*nums[j]){
//     //             count++;
//     //         }
//     //     }
//     //   } 
//     //   return count; 
    
    
//     }
// };

#include <vector>
using namespace std;

class Solution {
private:
    int count = 0;

    void merge(vector<int>& nums, int s, int mid, int e) {
        // --- 1. Count the Reverse Pairs ---
        int right_ptr = mid + 1;
        for (int i = s; i <= mid; i++) {
            // Use 2LL to prevent integer overflow errors
            while (right_ptr <= e && nums[i] > 2LL * nums[right_ptr]) {
                right_ptr++;
            }
            // All elements from mid + 1 up to right_ptr - 1 satisfy the condition
            count += (right_ptr - (mid + 1));
        }

        // --- 2. Standard Merge Step ---
        vector<int> temp;
        int i = s, j = mid + 1;

        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= e)   temp.push_back(nums[j++]);

        // Copy elements back to the original array
        for (int k = 0; k < temp.size(); k++) {
            nums[s + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e) return;
        
        int mid = s + (e - s) / 2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);
        merge(nums, s, mid, e);
    }

public:
    int reversePairs(vector<int>& nums) {
        count = 0; // Reset counter
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
