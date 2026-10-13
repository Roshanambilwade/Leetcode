class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<string>ans;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        vector<vector<string>>bucket(n+1);

        for(auto a:mp){
            
            bucket[a.second].push_back(a.first);
        }

        // Sort words alphabetically within each bucket
        for (auto &b : bucket) {
            sort(b.begin(), b.end());
        }
        for(int i=n;i>0;i--){
            for(int j=0;j<bucket[i].size() && k>0;j++){
                ans.push_back(bucket[i][j]);
                k--;
            }
        }
    return ans; 

    }
};