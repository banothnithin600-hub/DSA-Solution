class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(st.top()<=nums[i]){
                st.push(nums[i]);
                count++;
            }
        }
        // int count = 0;
        // while(!st.empty()){
        //     st.pop();
        //     count++;
        // }
        return count;
    }
};