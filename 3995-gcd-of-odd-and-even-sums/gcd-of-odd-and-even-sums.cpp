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
        if(n==1) return 1;
        if(n==0) return 0;
        long long evensum=0,oddsum=0,count=0;
        long long val = n*(n+1)/2;
        for(int i=1;i<=val;i++){
            if(count==n){
            if(i%2==0 ){
            evensum+=i;
            
            }else{
                oddsum+=i;
            }
            }
            count--;
        }
    return gcd(n*n,n*(n+1));
    }
};