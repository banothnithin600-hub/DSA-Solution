class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0; // Minimum possible open brackets needed
        int max_open = 0; // Maximum possible open brackets allowed

        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--; // If '*' acts as ')'
                max_open++; // If '*' acts as '('
            }

            // More ')' than possible '(' and '*' combined
            if (max_open < 0) return false; 
            
            // min_open cannot dip below 0 (we can't have negative required open brackets)
            if (min_open < 0) min_open = 0; 
        }

        // If min_open is 0, all open brackets can be validly closed
        return min_open == 0;
    }
};
