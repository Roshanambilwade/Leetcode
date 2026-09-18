class Solution {
public:
    bool isequal(vector<int>& nums,int curr,int rem,int n,vector<vector<int>>&dp){
        if(curr==rem){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n-1][rem] != -1){
            return dp[n-1][rem];
        }
        if(nums[n-1] > rem){
          return dp[n-1][rem] = isequal(nums,curr,rem,n-1,dp);
        }
        bool include = isequal(nums,curr+nums[n-1],rem-nums[n-1],n-1,dp);

        bool exclude = isequal(nums,curr,rem,n-1,dp);

        return dp[n-1][rem] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
         int n = nums.size();
       
       
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(total % 2 != 0) return false;

         vector<vector<int>>dp(n + 1, vector<int>(total + 1, -1));
        bool ans = isequal(nums,0,total,n,dp);

        return ans;


    }
};