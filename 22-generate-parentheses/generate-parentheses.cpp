// class Solution {
// public:
//   void print(int n ,vector<string>&ans,string &curr,int open,int close){
//     if(curr.size()/2==n){
//         ans.push_back(curr);
//         return;
//     }
//     if(open<n){
//         curr.push_back('(');
//         open++;
//         print(n,ans,curr,open,close);
//         curr.pop_back();
//         open--;
//     }
//     if(close<open){
//         curr.push_back(')');
//         close++;
//         print(n,ans,curr,open,close);
//         curr.pop_back();
//         close--;
//     }
//   }
//     vector<string> generateParenthesis(int n) {
//         string curr;
//         vector<string>ans;
//         int open = 0;
//         int close =0;
//         print(n,ans,curr,open,close);
//         return ans;
//     }
// };
class Solution {
public:
    vector<string> ans;

    void solve(string curr, int open, int close, int n) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n)
            solve(curr + "(", open + 1, close, n);

        if (close < open)
            solve(curr + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};