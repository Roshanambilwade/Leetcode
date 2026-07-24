class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>pair;
        for(int i=0;i<n;i++){ // O(n^2)
            for(int j=i;j<n;j++){
                pair.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>ans;
        for(int x:pair){
            for(int y : nums){
                ans.insert(x^y);
            }
        }
        return ans.size();
    }
};