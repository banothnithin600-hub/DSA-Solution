class Solution {
public:
    int scoreOfParentheses(string s) {
        int count = 0;
        // stack<char>st;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }else{
        //         if(st.top()=='(' && s[i]==')'){
        //             count++;
        //             st.pop();
        //         }
        //     }
        // }
        // return count;
         int depth = 0;
         int score = 0;
         for(int i=0;i<s.length();i++){
             if(s[i]=='('){
                depth++;
             }else{
                depth--;
                if(s[i-1]=='('){
                    score+=1<<depth;
                }
             }
         }
         return score;
    }
};