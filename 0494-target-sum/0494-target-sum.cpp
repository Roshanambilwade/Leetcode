class Solution {
public:
    void findexp(vector<int>& nums, int target,int &ans,int curr,int n){
        
        if(n == 0) {
            if(target == curr) {
                ans++;
            }
            return;
        }
       
        findexp(nums,target,ans,curr+nums[n-1],n-1);
        findexp(nums,target,ans,curr-nums[n-1],n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans =0;
        int n = nums.size();
        int curr = 0;
        findexp(nums,target,ans,curr,n);

        return ans;
    }
};