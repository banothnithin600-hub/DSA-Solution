#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<char, int> m;
        for (int i = 0; i < num.length(); i++) {
            m[num[i]]++;
        }

        string pairs = "";
        char middle = '\0';

        // 1. Corrected the missing loop: iterate through the map
        for (auto& x : m) {
            char digit = x.first;
            int count = x.second;

            // Take all possible pairs out of this digit's count
            int num_pairs = count / 2;
            for (int i = 0; i < num_pairs; i++) {
                pairs.push_back(digit);
            }

            // If there's a remainder, it's a candidate for the center middle element
            if (count % 2 != 0) {
                middle = max(middle, digit);
            }
        }

        // 2. Sort the pairs descending so the largest digits go to the front
        sort(pairs.begin(), pairs.end(), greater<char>());

        // 3. Prevent leading zeros (e.g., "00" becomes empty "")
        int first_non_zero = 0;
        while (first_non_zero < pairs.length() && pairs[first_non_zero] == '0') {
            first_non_zero++;
        }
        // Trim the leading zeros from the pairs string
        pairs = pairs.substr(first_non_zero);

        // 4. If we used any pairs, any leftover digit can be the middle.
        // If we have no pairs left, find the absolute largest single digit available.
        if (pairs.empty()) {
            char absolute_max = '0';
            for (auto& x : m) {
                if (x.second > 0) {
                    absolute_max = max(absolute_max, x.first);
                }
            }
            return string(1, absolute_max);
        }

        // 5. Construct the final palindrome string
        string left = pairs;
        string right = pairs;
        reverse(right.begin(), right.end());

        if (middle != '\0') {
            return left + middle + right;
        } else {
            return left + right;
        }
    }
};
