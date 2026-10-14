class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int st =0,end=nums.size()-1;
        while(st<end){
            if(nums[st]%2!=0 && nums[end]%2==0){
                swap(nums[st],nums[end]);
                st++;
                end--;
            }
            else if(nums[st]%2 == 0){
                st++;
            }
            else if(nums[end]%2 !=0){
                end--;
            }
        }
        return nums;
    }
};