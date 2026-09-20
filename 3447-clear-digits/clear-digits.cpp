class Solution {
public:
    string clearDigits(string s) {
        // string ans = "";
        // int cuntdigit = 0,cuntch=0;
        // string str = "",val="";
        // for(int i=0;i<s.length();i++){
        //     if(isdigit(s[i])){
        //         cuntdigit++;
        //     }else{
        //         cuntch++;
        //         val+=s[i];
        //     }
        // }
        // string v1 = "";
        // if(cuntdigit==cuntch){
        //     return ans;
        // }else if(cuntdigit<cuntch){
        //       v1+=val.substr(cuntdigit);
        // }
        // string v2="";
        // for(int i=0;i<v1.size();i++){
        //     if(isalpha(v1[i])){
        //         v2+=v1[i];
        //     }
        // }
        // return v2;
        stack<char>st;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        stack<char>st1;
        for(int i=0;i<ans.size();i++){
            st1.push(ans[i]);
        }
        string val = "";
        while(st1.size()>0){
            val+=st1.top();
            st1.pop();
        }
        return val;
    }
};