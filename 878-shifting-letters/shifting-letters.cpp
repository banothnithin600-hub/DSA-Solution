class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
       int n = shifts.size();
       vector<long long>actual(n);
       long long curr = 0;
       for(int i=n-1;i>=0;i--){
         curr = (curr+shifts[i])%26;
         actual[i]=curr;
       }
       
       for(int i=0;i<n;i++){
          s[i] = 'a' + (s[i]-'a' + actual[i])%26;
       }
       return s;
    }
};