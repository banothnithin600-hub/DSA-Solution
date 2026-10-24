class Solution {
public:
    int solve(int n){// divis by 2
        
        if(n<=0){
           return 0;
        }
         int by2 = n % 2 + solve(n / 2);
        int by3 = n % 3 + solve(n / 3);

        return 1 + min(by2, by3);
     }
    int minDays(int n) {
       return solve(n)-1;
    }
};