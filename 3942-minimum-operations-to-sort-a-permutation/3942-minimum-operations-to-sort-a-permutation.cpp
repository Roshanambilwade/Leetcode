class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Double the array
        vector<int> doubled(2 * n);

        for (int i = 0; i < n; i++) {
            doubled[i] = nums[i];
            doubled[i + n] = nums[i];
        }

        // Create sorted and descending arrays
        vector<int> sorted(n);
        vector<int> descending(n);

        for (int i = 0; i < n; i++) {
            sorted[i] = i;
            descending[i] = n - 1 - i;
        }

        // Find the positions of 0 and n-1
        int zeroPos = find(nums.begin(), nums.end(), 0) - nums.begin();
        int maxPos = find(nums.begin(), nums.end(), n - 1) - nums.begin();

        int ans = INT_MAX;

        // Check the ascending sequence only at zeroPos
        if (equal(sorted.begin(), sorted.end(),
                  doubled.begin() + zeroPos)) {

            ans = min(ans, min(zeroPos, n - zeroPos + 2));
        }

        // Check the descending sequence only at maxPos
        if (equal(descending.begin(), descending.end(),
                  doubled.begin() + maxPos)) {

            ans = min(ans, 1 + min(maxPos, n - maxPos));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};