class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> m;
        int ans = 0;
        for (int i = -1, j = 0; j < size(word); j++) {
            if (vowel.find(word[j]) == end(vowel)) {
                m.clear();
                i = j;
                continue;
            }
            m[word[j]] = j;
            if (size(m) == 5) {
                int k = j;
                for (auto& [c, idx]: m) k = min(k, idx);
                ans += k - i;
            }
        }
        return ans;
    }
};