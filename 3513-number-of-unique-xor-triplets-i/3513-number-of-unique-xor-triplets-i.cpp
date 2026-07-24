class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans  = 2;
        if(n<3){
            return n;
        }
        else{
           
            while(ans<=n){
                ans*=2;
            }
        }
        return ans;
    }
};