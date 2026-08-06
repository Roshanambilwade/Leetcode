class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mx = INT_MIN;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            mx = max(sum,mx);
            i++;
            j--;
        }
        return mx;
    }
};