class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(st.top()<=nums[i]){
                st.push(nums[i]);
            }
        }
        int count = 0;
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};