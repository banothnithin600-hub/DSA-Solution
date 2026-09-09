class Solution {
public:
    long long countCommas(long long n) {
        long long r =0;
        long long t = 1000;
        while(t<=n){
            r+=n-t+1;
            t*=1000;
        }
        return r;
    }
};