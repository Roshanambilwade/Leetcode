class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
                // Save the string before '('
                st.push(curr);
                curr = "";
            }

            else if (ch == ')') {
                // Reverse the content inside parentheses
                reverse(curr.begin(), curr.end());

                // Add it to the string before '('
                curr = st.top() + curr;
                st.pop();
            }

            else {
                // Normal character
                curr += ch;
            }
        }

        return curr;
    }
};