class Solution {
public:
    int divide(int n, int q) {
        if(n==q) return 1;
        long long int val = (long long)n/q;
        if(val>INT_MAX)
        return INT_MAX;
        if(val<INT_MIN)
        return INT_MIN;
        return val;
    }
};