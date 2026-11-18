class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // stack<int>st,st1;
        // int count = 1;
        // st.push(arr[0]);
        // for(int i=1;i<arr.size();i++){
        //     if(st.top()<arr[i]){
        //        count++;
        //     }else{
        //         st.pop();
        //     }
        //     st.push(arr[i]);
        // }

        // return count;
        int n = arr.size();
        int maxl = 0;
        int count = 0;
        for(int  i=0;i<n;i++){
            maxl = max(maxl,arr[i]);
            if(i==maxl){
                count++;
            }
        }
        return count;
    }
};