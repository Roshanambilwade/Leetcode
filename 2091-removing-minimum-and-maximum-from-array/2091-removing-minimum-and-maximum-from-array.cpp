class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        if(n==1) return 1;

        for (int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);  // removed int
            mx = max(mx, nums[i]);  // removed int
        }

        int mni;
        int mxi;
        for(int i=0;i<n;i++){
            if(nums[i]==mx){
                mxi = i;
            }
             if(nums[i]==mn){
                mni = i;
            }

        }

        int a = max(mni,mxi)+1;
        int b = n - min(mni,mxi);

        int c = (mxi+1) + (n-mni);

        int d = (mni+1) + (n-mxi);

        return min({a,b,c,d});
    }
};