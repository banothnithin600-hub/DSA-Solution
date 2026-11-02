class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack<char>st;
         int n = s.size();
        // unordered_set<int>remove;
        // for(int i=0;i<n;i++){
        //    if(s[i]=='('){
        //       st.push(i);
        //    }else if(s[i]==')'){
        //     if(!st.empty()){
        //         st.pop();
        //     }else{
        //         remove.insert(i);
        //     }
        //    }
        // }
        // while(!st.empty()){
        //     remove.insert(st.top());
        //     st.pop();
        // }
        // string ans = "";
        // for(int i=0;i<s.size();i++){
        //      if(!remove.count(i)){
        //         ans+=s[i];
        //      }
        // }
        // return ans;
        int open = 0,close = 0;
        string str = "";
        for(int i=0;i<n;i++){
             if(s[i]=='('){
                open++;
             }else if(s[i]==')'){
                if(open==0){
                    continue;
                }
                open--;
             }
             str+=s[i];
        }

        string ans = "";
        close=open;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='(' && close>0){
                close--;
                continue;
            }
            ans+=str[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


















// leet(t(c)o)de ==> find idx we can remove that idx , is correct

// approach: 1
// 1. stack approach
// 2. first pushing idx and opening and close brac.. onit
// 3. form stack if isvalid i will remove valid brack.. and idx.. remaining bac... and idx.. we will remove back... i will add idx only onit

//approach 2: two pass optimal 
