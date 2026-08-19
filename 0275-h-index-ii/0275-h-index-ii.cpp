class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();

        int low = 0;
        int high = n - 1;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int csum = n - mid;

            if(c[mid] >= csum){
                ans = csum;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};