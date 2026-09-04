class Solution {
public:
    int digit(int n){
        int val ;
        while(n>0){
            val = n%10;
            n/=10;
        }
        return val;
    }
    long long powerMod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        long long MOD = 1000000007;
        for(auto num:nums){
            long long w = num%10;
            long long d = num/10;
            string s = to_string(d);
            int len = s.length();
            if (w <= 0 || w >= len) continue;
            long long x = stoll(s.substr(0,w));
            long long y = stoll(s.substr(w));
            long long val = powerMod(x, y, MOD);
            sum=(sum+val)%MOD;
        }
        return sum;
    }
};