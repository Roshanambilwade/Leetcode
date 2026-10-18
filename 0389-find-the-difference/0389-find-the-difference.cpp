
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;

        // Count the frequency of characters in s
        for (char c : s) {
            freq[c]++;
        }

        // Find the extra character in t
        for (char c : t) {
            if (freq[c] == 0) {
                return c;
            }
            freq[c]--;
        }

        return ' ';
    }
};
