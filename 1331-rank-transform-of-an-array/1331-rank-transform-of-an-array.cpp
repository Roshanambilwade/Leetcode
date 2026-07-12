class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>sortans = arr;
        sort(sortans.begin(),sortans.end());
        vector<int>ans(arr.size(),0);
        int count = 1;
        for(int i =0;i<arr.size();i++){
            if(mp.find(sortans[i]) != mp.end()){
                continue;
            }
            else{
            mp[sortans[i]] = count;
            count++;
            }
        }
        for(int i = 0;i<arr.size();i++){
            ans[i] = mp[arr[i]];
        }
    return ans;
    }
};