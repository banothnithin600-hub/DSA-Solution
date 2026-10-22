class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>st;
       int targetpoint = 0,steampointer = 1;
       while(targetpoint<target.size()){
          st.push_back("Push");
          if(target[targetpoint]==steampointer){
               targetpoint++;
          }else{
              st.push_back("Pop");
          }
          steampointer++;
       }
       return st;
    }
};