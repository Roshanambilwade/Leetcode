class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;

        int ans1 = 1;
        int ans2 = 1;

        for(int i=1;i<nums.size();i++){
            // inc 
            if(nums[i]>nums[i-1]){
                ans1++;
                inc = max(inc,ans1);
            }
            else{
                ans1 = 1;
            }

            // dec
            if(nums[i]<nums[i-1]){
                ans2++;
                dec = max(dec,ans2);
            }
            else{
                ans2 =1;
            }
        }
        return max(inc,dec);
    }
};