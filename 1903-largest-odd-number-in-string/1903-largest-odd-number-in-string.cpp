class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";
        for(int i=n;i>=0;i--){
            int n = num[i]-'0';
            if(n%2 != 0 ){
                ans  = num.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};