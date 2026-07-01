class Solution {
public:
int sumSqDigits(int x) {
    int s = 0;
    while (x > 0) {
        int d = x % 10;
        s += d * d;
        x /= 10;
    }
    return s;
}

bool isHappy(int n) {
    int slow = sumSqDigits(n);
    int fast = sumSqDigits(sumSqDigits(n));

    while (slow != fast) {
        if (fast == 1) return true;

        slow = sumSqDigits(slow);
        fast = sumSqDigits(sumSqDigits(fast));
    }
    return slow == 1;
}


};