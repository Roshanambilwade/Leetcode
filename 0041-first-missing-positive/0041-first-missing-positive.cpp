class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i] <=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0;i<n;i++){
            int v = i+1;
            if(nums[i] != v){
                return v;
                

            }
        }
        return n+1;
    }
};