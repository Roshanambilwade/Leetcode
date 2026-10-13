class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>p(mp.begin(),mp.end());
        sort(p.begin(),p.end(),[](auto &a,auto&b){
            return a.second>b.second;
        });
      for(int i=0;i<k;i++){
        ans.push_back(p[i].first);
      }

       return ans;
    }
};