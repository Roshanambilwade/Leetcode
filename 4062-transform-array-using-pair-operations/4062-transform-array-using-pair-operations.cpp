class Solution {
public:
    bool canTransform(vector<int>& s, vector<int>& t) {
        int n = s.size();
        long long fir = 0;
        long long sec =0;

        for(int i=0;i<n;i++){
            fir+=s[i];
            sec+=t[i];
        }
        if(fir==sec) return true;
        else return false;
    }
};