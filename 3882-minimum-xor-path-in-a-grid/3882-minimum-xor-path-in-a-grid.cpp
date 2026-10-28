class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int xr) {
        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            return xr;
        }

        if (dp[i][j][xr] != -1) {
            return dp[i][j][xr];
        }

        int ans1 = INT_MAX;
        int ans2 = INT_MAX;

        if (j + 1 < n) {
            ans1 = solve(grid, i, j + 1, xr);
        }

        if (i + 1 < m) {
            ans2 = solve(grid, i + 1, j, xr);
        }

        return dp[i][j][xr] = min(ans1, ans2);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int MAX_XOR = 1024; // Adjust according to constraints

        dp.assign(
            m,
            vector<vector<int>>(
                n, vector<int>(MAX_XOR, -1)
            )
        );

        return solve(grid, 0, 0, 0);
    }
};