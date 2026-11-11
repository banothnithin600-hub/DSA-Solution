class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long both  = min(need1,need2); // we are finding oveerlapping
        long long costA = 1LL*need1*cost1+1LL*need2*cost2;
        long long costB = both*costBoth + 1LL*(need1-both)*cost1 + 1LL *(need2-both)*cost2;
        long long costC = 1LL*max(need1,need2)*costBoth;
        return min({costA,costB,costC});

    }
};