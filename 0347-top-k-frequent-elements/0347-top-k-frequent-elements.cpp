class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        // sorting approach

    //     vector<pair<int,int>>p(mp.begin(),mp.end());
    //     sort(p.begin(),p.end(),[](auto &a,auto&b){
    //         return a.second>b.second;
    //     });
    //   for(int i=0;i<k;i++){
    //     ans.push_back(p[i].first);
    //   }

    /// bucket sort approach
    vector<vector<int>>bucket(n+1);
    for(auto it:mp){
        bucket[it.second].push_back(it.first);
    }

    for(int i=n;i>0;i--){
        
            for(int j=0;j<bucket[i].size() && k>0;j++){
                ans.push_back(bucket[i][j]);
                k--;
            }
            if(k<=0) break;
        
    }

       return ans;
    }
};