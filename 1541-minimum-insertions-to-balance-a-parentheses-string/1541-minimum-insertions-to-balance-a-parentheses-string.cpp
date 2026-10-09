
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                // Complete the previous pair if needed
                if (balance % 2 == 1) {
                    ans++;
                    balance--;
                }

                // Each '(' requires two ')'
                balance += 2;
            } 
            else {
                balance--;

                // An unmatched ')' requires an inserted '('
                if (balance < 0) {
                    ans++;
                    balance = 1;
                }
            }
        }

        // Insert any missing closing parentheses
        return ans + balance;
    }
};
