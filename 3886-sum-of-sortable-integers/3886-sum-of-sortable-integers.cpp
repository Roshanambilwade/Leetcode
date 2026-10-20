class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
         int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool possible = true;

            for (int start = 0; start < n; start += k) {
                vector<int> a(nums.begin() + start,
                              nums.begin() + start + k);

                vector<int> target(sorted.begin() + start,
                                   sorted.begin() + start + k);

                vector<int> doubled = a;
                doubled.insert(doubled.end(), a.begin(), a.end());

                bool found = false;

                for (int i = 0; i < k; i++) {
                    if (equal(target.begin(), target.end(),
                              doubled.begin() + i)) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans += k;
            }
        }

        return ans;
    }
};