class Solution {
public:
    int clumsy(int n) {
        //if(n==0 || n==1) return n;
       stack<int>st;
       st.push(n);
       int idx=1;
       for(int i=n-1;i>0;i--){
        if(idx==1){
            int v = st.top();
            st.pop();
            st.push(v*i);
        }
        else if(idx==2){
            int v = st.top();
            st.pop();
            st.push(v/i);
    
        }else if(idx==3){
            st.push(i);
        }else{
            st.push(-i);
            idx=0;
        }
        idx++;
       }
       int ans = 0;
       while(!st.empty()){
          ans+=st.top();
          st.pop();
       }
       return ans;
    }
};