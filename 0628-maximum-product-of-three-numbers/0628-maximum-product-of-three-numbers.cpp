class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long int p  = nums[n-1]*nums[n-2] * nums[n-3];
        long long pn = nums[0] * nums[1] * nums[2];
        return max(p,pn);
    }
};