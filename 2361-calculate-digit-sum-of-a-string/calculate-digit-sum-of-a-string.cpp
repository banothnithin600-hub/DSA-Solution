class Solution {
public:
    string digitSum(string s, int k) {
       string ans = ""; 
    int n = s.length(); 
    if(n<=k) return s;
    for(int i=0;i<n;i+=k){ 
        int num = 0; 
        for(int j=i;j<min(i+k,n);j++){ 
            num+=s[j]-'0'; 
        } 
        ans+=to_string(num); 
        } 
        if(ans.size()<=k){ 
            return ans; 
        }
        return digitSum(ans,k);
    }
};