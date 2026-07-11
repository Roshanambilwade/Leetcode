class Solution {
public:
   
    int arithmeticTriplets(vector<int>& nums, int diff) {
         int count = 0;
        unordered_set<int>mp(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mp.count(diff+nums[i]) && mp.count(2*diff+nums[i])){
                count++;
            }
        }
        return count;
    }
};