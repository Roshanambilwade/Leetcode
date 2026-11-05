class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxm = *max_element(nums.begin(),nums.end());
        int minm = *min_element(nums.begin(),nums.end());
        int count =0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>minm && nums[i]<maxm){
                count++;
            }
        }
        return count;
    }
};