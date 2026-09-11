class Solution {
    private:
    void backtrack(vector<int>& count, set<int>& unique_nums,
                   int current_num, int length) {

        // Base case
        if (length == 3) {
            if (current_num % 2 == 0) {
                unique_nums.insert(current_num);
            }
            return;
        }

        // Try every digit
        for (int digit = 0; digit <= 9; digit++) {

            // First digit cannot be 0
            if (length == 0 && digit == 0)
                continue;

            // Digit is available
            if (count[digit] > 0) {

                // Choose
                count[digit]--;

                // Explore
                backtrack(count, unique_nums,
                          current_num * 10 + digit,
                          length + 1);

                // Undo
                count[digit]++;
            }
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
      vector<int> count(10, 0);

        for (int d : digits) {
            count[d]++;
        }

        set<int> unique_nums;

        backtrack(count, unique_nums, 0, 0);

       return unique_nums.size();
    }
};