class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int l=0,r=0;
        unordered_map<int,int>mp;
        int mx = 0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }

            mx = max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};