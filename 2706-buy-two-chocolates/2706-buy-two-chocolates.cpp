class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        sort(nums.begin(),nums.end());
        
        if(nums[0]+nums[1]<=money){
            return money-(nums[0]+nums[1]);
        }
        else{
            return money;
        }
    }
};