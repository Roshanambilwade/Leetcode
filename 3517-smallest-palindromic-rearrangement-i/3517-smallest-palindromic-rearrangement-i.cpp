class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency
        for (char ch : s)
            freq[ch - 'a']++;

        string first = "";
        string middle = "";

        // Build first half
        for (int i = 0; i < 26; i++) {
            first += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 == 1)
                middle = char('a' + i);
        }

        // Second half
        string second = first;
        reverse(second.begin(), second.end());

        return first + middle + second;
    }
};