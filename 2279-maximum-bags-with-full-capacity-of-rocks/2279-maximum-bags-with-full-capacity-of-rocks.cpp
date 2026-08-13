class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int additionalRocks) {
        int n = r.size();
        // vector<pair<int,int>v(n,make_pair(0,0));
        // for(int i = 0;i<n;i++){
        //     int need = c[i]-r[i];
        //     v[i] = make_pair(need,i);
        // }
        // find needed rock for each bag

        vector<int>need(n);
        for(int i=0;i<n;i++){
            need[i] = c[i] - r[i];
        }
        sort(need.begin(),need.end());

        int ans = 0;
        int rem = additionalRocks;
        for(int i=0;i<n;i++){
            if(need[i]<=rem){
                ans++;
                rem -= need[i];
            }
            if(rem==0){
                break;
            }
        }
        return ans;
    }
};