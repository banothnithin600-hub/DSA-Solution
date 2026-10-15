class Solution {
public:
    bool isvaild(vector<char>ans){
        int left = 0;
        int right = ans.size()-1;
        while(left<=right){
            if(ans[left]==ans[right]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                st.push(tolower(s[i]));
            }
        }
       vector<char>ans;
       while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
       }
      return isvaild(ans);
    }
};