class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>must = heights;
        sort(must.begin(),must.end());
        int ans = 0;
        for(int i=0;i<must.size();i++){
            if(heights[i] != must[i]){
                ans++;
            }
        }
        return ans;
    }
};