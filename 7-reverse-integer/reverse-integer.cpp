class Solution {
public:
    int reverse(int x) {
      int n = x;
      int val = 0;
      while(n!=0){
        int rem = n%10;
        if(val>INT_MAX/10 || val<INT_MIN/10){
            return 0;
        }
         val = val*10+rem;
         n/=10;
      }
      return val;
    }
};