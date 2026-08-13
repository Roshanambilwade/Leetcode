class Solution {
public:
    int maximumUnits(vector<vector<int>>& bx, int truckSize) {
        sort(bx.begin(),bx.end(),
        [](vector<int>a, vector<int>b){
            return a[1]>b[1];
        });
        int ans = 0;
        int w = truckSize;
        for(int i=0;i<bx.size();i++){
            int wt = bx[i][0];
            if(wt<=w){
                ans+=bx[i][1]*wt;
                w-=wt;
            }
            else{
                ans+=w*bx[i][1];
                break;

            }
        }
        return ans;
    }
};