class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int ans = 0;
        int c = coins;
        for(int i=0;i<n;i++){
            if(costs[i]<=c){
                ans++;
                c-=costs[i];
            }
            if(c==0) break;
        }
        return ans;
    }
};