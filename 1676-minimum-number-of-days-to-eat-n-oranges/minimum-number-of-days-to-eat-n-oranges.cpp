class Solution {
public:
    unordered_map<int,int>memo;
    int solve(int n){
        if(n<=0){
           return 0;
        }
        if(memo.count(n)) return memo[n];
         int by2 = n % 2 + solve(n / 2); // rem + solve(n/2)
        int by3 = n % 3 + solve(n / 3); //rem + solve(n/3)

        memo[n]=1 + min(by2, by3);
        return memo[n];
     }
    int minDays(int n) {
       return solve(n)-1;
    }
};