class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < rs.size(); i++) {
            mp[rs[i][0]].push_back(rs[i][1]);
        }

        int ans = n * 2;

        for(auto x : mp) {
            vector<int> v = x.second;

            bool left = true;
            bool mid = true;
            bool right = true;

            for(int j = 0; j < v.size(); j++) {
                if(v[j] >= 2 && v[j] <= 5)
                    left = false;

                if(v[j] >= 4 && v[j] <= 7)
                    mid = false;

                if(v[j] >= 6 && v[j] <= 9)
                    right = false;
            }

            if(left && right) {
                // This row can still have 2 families
                continue;
            }
            else if(left || mid || right) {
                // This row can have only 1 family
                ans -= 1;
            }
            else {
                // This row cannot have any family
                ans -= 2;
            }
        }

        return ans;
    }
};