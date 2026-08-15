class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        bool nonzero = false;

        for(int x:nums){
            mx = mx^x;
            if(x!=0){
                nonzero = true;
            }
        }
        if(mx!=0){
            return n;
        }
        else if(nonzero){
            return n-1;
        }
        else{
            return 0;
        }
        
    }
};