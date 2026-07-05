class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=n*2-1;i>=0;i--){
            while(!s.empty() && nums[i%n]>=s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i%n] = -1;
                s.push(nums[i%n]);
            }
            else{
                ans[i%n] = s.top();
                s.push(nums[i%n]);
            }
        }
        return ans;
    }
};