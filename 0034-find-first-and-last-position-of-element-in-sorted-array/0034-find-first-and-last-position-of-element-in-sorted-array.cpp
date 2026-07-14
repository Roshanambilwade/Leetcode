class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int fa = -1;
        int la = -1;
        int n = nums.size();
        int l = 0;
        int h = n- 1;

        // first search for first element
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==tar){
                fa = mid;
                h = mid-1;
            }
            else if(nums[mid]<tar){
                l = mid+1;
            }
            else{
                h = mid-1;
            }

        }
        // for second logic 
        // first search for first element

        l =0,h = n-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==tar){
                la = mid;
                l  = mid+1;
            }
            else if(nums[mid]<tar){
                l = mid+1;
            }
            else{
                h = mid-1;
            }

        }
        return {fa,la};
    }
};