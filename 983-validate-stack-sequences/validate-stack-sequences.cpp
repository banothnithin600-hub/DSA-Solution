class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        if(m != n) return false;

        stack<int> st1, st2;
        for(int i = m - 1; i >= 0; i--) {
            st2.push(popped[i]);
        }

        for(int i = 0; i < n; i++) {
            st1.push(pushed[i]); 
            while(!st1.empty() && !st2.empty() && st1.top() == st2.top()) {
                st1.pop();
                st2.pop();
            }
        }
      
        return st1.empty() && st2.empty();
    }
};
