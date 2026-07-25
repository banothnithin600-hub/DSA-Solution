class Solution {
public:
    int rangeBitwiseAnd(int n, int y) {
    //     while(n>0 || y>0){
    //         n/=2;
    //     y/=2;
    //    n%2&&y%2;
        
    // }
    // return 0;
    // long long a= n&y;
    // return a;
       while(y>n){//making 101 &{(111(n) & 110(n-1))=6} repeared till y>n
       y=y&(y-1);
   }
    return y;
    }
};