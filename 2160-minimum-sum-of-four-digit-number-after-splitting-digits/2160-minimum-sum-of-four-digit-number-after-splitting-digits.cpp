class Solution {
public:
    int minimumSum(int num) {
        vector<int>ans;

        int n = num;
        while(n>0){
            int ld = n%10;
            ans.push_back(ld);
            n = n/10;

        }
        sort(ans.begin(),ans.end());
        int n1 = ans[0]*10 + ans[3];
        int n2 = ans[1]*10 + ans[2];

        return n1+n2;
    }
};