class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n= nums.size();
        int count = 0;
        for(int val : nums){
            int digit = 0;
            while(val>0){
                digit++;
                val = val/10;
            }
            if(digit%2==0){
                count++;
            }
        }
        return count;
    }
};