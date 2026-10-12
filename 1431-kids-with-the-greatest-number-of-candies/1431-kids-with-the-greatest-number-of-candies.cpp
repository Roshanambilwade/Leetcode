class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int ec) {
        int n= can.size();
        vector<bool>ans(n);
        int m = INT_MIN;
        for(int i=0;i<n;i++){
            m = max(m,can[i]);
        }
        for(int i=0;i<n;i++){
            int tot = can[i]+ec;
            if(tot>=m){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};