// class Solution {
// public:
//     int helper(string s){
//         unordered_map<char,int>mp;
//         for(int i=0;i<s.length();i++){
//             mp[s[i]]++;
//         }
//         int minl = INT_MAX,maxl=INT_MIN;
//         for(auto x:mp){
//             minl = min(minl,x.second);
//             maxl = max(maxl,x.second);
//         }
//         return maxl-minl;
//     }
//     int beautySum(string s) {
//      long long  val = 0;
//      for(int i=0;i<s.length();i++){
//         for(int j=i+1;j<s.length();j++){
//         string str = s.substr(i,j-i+1);
//           val+=helper(str);
//         }
//      }
//      return val;
//     }
// };

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }

                ans += maxi - mini;
            }
        }

        return ans;
    }
};