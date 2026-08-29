class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(j.find(s[i]) < j.length()){
                ans++;
            }
        }
        return ans;
    }
};