class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mind = INT_MAX;
        for(int i=0;i<n-1;i++){
            int absd = abs(arr[i]-arr[i+1]);
            mind = min(mind,absd);
        }
       
        for(int i=0;i<n-1;i++){
            int diff = abs(arr[i]-arr[i+1]);
            if(diff == mind){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};