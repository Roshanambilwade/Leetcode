class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // '*' can be ')'
                high++;     // '*' can be '('
            }

            // Even the maximum possibility is negative
            if (high < 0) {
                return false;
            }

            // We cannot have negative unmatched '('
            if (low < 0) {
                low = 0;
            }
        }

        return low == 0;
    }
};