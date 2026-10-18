class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>exp(n);
        vector<pair<int,int>>p(n);

        for(int i=0;i<n;i++){
            int curr =0;
            int val = nums[i];
            while(val>0){
                int ld = val%10;
                curr+=ld;
                val = val/10;
            }
            p[i] = make_pair(nums[i],curr);
        }
        sort(p.begin(),p.end(),[](auto &a,auto &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        for(int i=0;i<n;i++){
            exp[i] = p[i].first;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
int ans = 0;

for(int i = 0; i < n; i++) {
    if(nums[i] == exp[i]) {
        continue;
    }

    int idx = mp[exp[i]];

    swap(nums[i], nums[idx]);

    mp[nums[i]] = i;
    mp[nums[idx]] = idx;

    ans++;
}

return ans;
        

     
    }
};