class Solution {
public:
    int trap(vector<int>& h) {
        // prefix array approach
        int n = h.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        int ans = 0;

        lmax[0] = h[0];
        rmax[n-1] = h[n-1];

        // find lmax
        for(int i = 1;i<n;i++){
            lmax[i] = max(lmax[i-1],h[i]);
        }

        // find rmax
        for(int i= n-2;i>=0;i--){
            rmax[i] = max(rmax[i+1],h[i]);
        }
        // finnaly find ans

        for(int i=0;i<n;i++){
            ans+= min(lmax[i],rmax[i])-h[i];
        }
        return ans;
    }
};