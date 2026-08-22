class Solution {
public:
   
    bool checkDivisibility(int n) {
        int m = n;
        int val = 0;
        int prod=1;
        while(n>0){
            int v1=n%10;
            prod *=v1;
            val+=v1;
            n/=10;
        }
       return m%(val+prod)==0;
    }
};