class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total=0;
        for(int x:nums){
            total+=x;
        }
        int maxl = -1;

        long long target = total-x;
        if(target < 0) return -1;

        int l=0,r=0;
        long long curr=0;
        int len = 0;
        while(r<n){
            curr+=nums[r];
            len++;

           
            while(curr>target){
                curr-=nums[l];
                len--;
                l++;
            }
             if(curr==target){
                maxl = max(maxl,len);
            }

            r++;
        }
       
    if(maxl == -1) return -1;
        return n-maxl;
    }
};