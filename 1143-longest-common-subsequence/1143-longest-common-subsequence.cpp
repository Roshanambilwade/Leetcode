class Solution {
public:
    int findcommon(string &t1, string &t2,int n,int m, vector<vector<int>>&dp){
      

        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(t1[n-1]==t2[m-1]){
            return dp[n][m] =  1 + findcommon(t1,t2,n-1,m-1,dp);
        }
        int ans1 = findcommon(t1,t2,n-1,m,dp);
        int ans2 = findcommon(t1,t2,n,m-1,dp);
        
        return dp[n][m] =  max(ans1,ans2);
    }
    int longestCommonSubsequence(string t1, string t2) {
         int n = t1.length();
        int m = t2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return findcommon(t1,t2,n,m,dp);
        
    }
};