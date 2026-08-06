class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int s = 2*n;
        vector<int>ans(s);
        for(int i =0;i<2*n;i++){
            ans[i] = nums[i%n];
        }
        return ans;
    }
};