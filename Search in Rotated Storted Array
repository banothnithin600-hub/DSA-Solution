class Solution {
public:
    int search(vector<int>& n, int target) {
        // int start = 0;
        // int end = n.size() - 1;

        // while (start <= end) {
        //     int mid = start + (end - start) / 2; 

        //     if (n[mid] == target) {
        //         return mid;
        //     }
        //     if (n[start] <= n[mid]) {
        //         if (n[start] <= target && target < n[mid]) {//left part searching 
        //             end = mid - 1; 
        //         } else {
        //             start = mid + 1; 
        //         }
        //     } 
        
        //     else {//right part searching
        //         if (n[mid] < target && target <= n[end]) {
        //             start = mid + 1; 
        //         } else {
        //             end = mid - 1;
        //         }
        //     }
        // }

        // return -1; 


        //approch 2
        for(int i=0;i<n.size();i++){
            if(n[i]==target) return i;
        }
        return -1;
    }
};
