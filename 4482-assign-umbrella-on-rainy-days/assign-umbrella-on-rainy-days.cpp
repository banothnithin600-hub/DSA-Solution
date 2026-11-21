class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string>ans;
        string s1 = "Alice";
        string s2 = "Bob";
        string s3 = "None";
        int alice = 0;
        int bob = 0;
        for(int i=0;i<n-1;i++){
            if(rain[i]==1 && rain[i+1]==1){
                if(alice<=bob){
                                 ans.push_back(s1);
                    alice++;
                }else{
                    ans.push_back(s2);
                    bob++;
                }

            } else if(rain[i]==0){
                ans.push_back(s3);
            } else if(rain[i]==1){
                ans.push_back(s2);
                bob++;
            }
        }
        if(rain[n-1]==1){
            ans.push_back("Bob");
        }else{
            ans.push_back("None");
        }
        return ans;
    }
};