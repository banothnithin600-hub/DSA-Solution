class Solution {
public:
  void print(int n ,vector<string>&ans,string &curr,int open,int close){
    if(curr.size()/2==n){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        curr.push_back('(');
        open++;
        print(n,ans,curr,open,close);
        curr.pop_back();
        open--;
    }
    if(close<open){
        curr.push_back(')');
        close++;
        print(n,ans,curr,open,close);
        curr.pop_back();
        close--;
    }
  }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string>ans;
        int open = 0;
        int close =0;
        print(n,ans,curr,open,close);
        return ans;
    }
};