class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(),count=0;
        int xorr = 0;
        bool isAllzero =true;
         
        for(int i=0;i<n;i++){
            xorr^=nums[i];
            
            if(nums[i]!=0){
                isAllzero = false;
            }
        }
            if(xorr!=0){//if xor is not zero return size of subseq.. array
                return n;
            }
            if(isAllzero) return 0;//if subseq.. array is zero return 0
        return n-1;
    }
};