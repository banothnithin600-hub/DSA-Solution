class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string res = "";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch=='('){
                st.push(res.length());
            }else if(ch==')'){
                 int start = st.top();
                 st.pop();
                 int end = res.length()-1;
                 reve(res,start,end);
            }else{
                res+=ch;
            }
        }
        return res;
    }
    void reve(string &sb,int start,int end){
        while(start<end){
            swap(sb[start],sb[end]);
            start++;
            end--;
            
        }
    }
};