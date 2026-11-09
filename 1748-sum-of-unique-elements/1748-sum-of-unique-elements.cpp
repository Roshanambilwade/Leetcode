class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        long long ans = 0;
        for(int i=0;i<n;i++){
          mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<2){
                ans+=nums[i];
            }
        }
        return ans;
    }
};