class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int>s;

        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[j] > nums[i]) {
        //             nge[i] = nums[j];
        //             break;
        //         }
        //     }
        // }
        // return nge;
        for(int i=n-2;i>=0;i--){
            if(!s.empty() && s.top()<nums[i]){
                s.pop();
            }
            if(s.empty()) nge[i]=-1;
            else nge[i] = s.top();
            s.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
    while(!s.empty() && s.top()<=nums[i]){
        s.pop();
        }
        if(!s.empty()) nge[i] = s.top();
        else nge[i] = -1;
        s.push(nums[i]);
        
    }
        return nge;
    }
};
