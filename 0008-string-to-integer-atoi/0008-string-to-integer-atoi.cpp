class Solution {
public:
    int myAtoi(string s) {
        string ans;
        bool signFound = false;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ' && ans.length() == 0 && !signFound) {
                continue;
            }

            if ((s[i] == '-' || s[i] == '+') && 
                ans.length() == 0 && !signFound) {

                signFound = true;

                if (s[i] == '-') {
                    ans.push_back(s[i]);
                }

                continue;
            }

            if (!isdigit(s[i])) {
                break;
            }
            else {
                ans.push_back(s[i]);
            }
        }

        if (ans.length() == 0 || ans == "-") {
            return 0;
        }

        long long number = 0;
        int sign = 1;
        int i = 0;

        if (ans[0] == '-') {
            sign = -1;
            i++;
        }

        for (; i < ans.length(); i++) {
            number = number * 10 + (ans[i] - '0');

            if (sign * number > INT_MAX)
                return INT_MAX;

            if (sign * number < INT_MIN)
                return INT_MIN;
        }

        return sign * number;
    }
};