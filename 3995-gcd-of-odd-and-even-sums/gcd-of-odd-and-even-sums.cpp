class Solution {
public:
    int gcd(int a, int b)
{
    // Everything divides 0
    if(a==0 || b==0) return max(a, b);
    
    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    // Return gcd of a and b
    return result;
}
int gcdOfOddEvenSums(int n) {
    //return gcd(n*n,n*(n+1));
    return n;
    }
};