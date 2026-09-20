class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            int idx = i+1;
            int deg = 'z'-s[i] + 1;
            ans+=(idx*deg);
        }
        return ans;
    }
};