class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int ans =0;
        int depth =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }
            else if(s[i]==')'){
                depth--;
                if(s[i-1]=='('){
                    ans+=pow(2,depth);
                }
            }

        }
        return ans;
    }
};