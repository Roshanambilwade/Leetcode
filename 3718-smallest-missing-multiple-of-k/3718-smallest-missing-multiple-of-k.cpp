class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());

        int ans = k;
        while(true){
            if(s.find(ans) == s.end()){
                break;
            }
            else{
                ans+=k;
            }
        }
        return ans;
    }
};