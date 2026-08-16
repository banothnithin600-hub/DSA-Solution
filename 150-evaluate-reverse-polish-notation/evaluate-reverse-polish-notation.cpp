class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=="+"){
                int v1 =st.top();
                st.pop();
                int v2 = st.top();
                 st.pop();
                 ans=v1+v2;
                 st.push(ans);
            }else if(s[i]=="-"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                 st.pop();
                 ans=v2-v1;
                 st.push(ans);
            }else if(s[i]=="*"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                 st.pop();
                 ans=v1*v2;
                 st.push(ans);
            }else if(s[i]=="/"){
                int v1 = st.top();
                st.pop();
                int v2 =st.top();
                 st.pop();
                 ans=v2/v1;
                 st.push(ans);
            }else{
                st.push(stoi(s[i]));
            }
        }
        ans = st.top();
        st.pop();
        return ans;
    }
};