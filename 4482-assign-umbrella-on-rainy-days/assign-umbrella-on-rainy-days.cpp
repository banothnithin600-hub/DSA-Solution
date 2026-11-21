class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
         int n=rain.size();
        vector<string>ans(n);
       
        int cntal=0,cntbo=0;
        for(int i=0;i<n-1;i++){
            if(rain[i]==0) ans[i]="None";
            else if(rain[i]==1&&rain[i+1]==1&&cntal<=cntbo){
                cntal++;
                ans[i]="Alice";
            }else{
                cntbo++;
                ans[i]="Bob";

            }
        }
        if(rain[n-1]==0)ans[n-1]="None";
        else ans[n-1]="Bob";
        return ans;

    }
};