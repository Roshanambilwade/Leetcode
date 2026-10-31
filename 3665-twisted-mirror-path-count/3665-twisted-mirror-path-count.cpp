
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long findpath(vector<vector<int>>& grid, int i, int j, int d,
                       vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j][d] != -1)
            return dp[i][j][d];

        int cell = grid[i][j];
        long long ans = 0;

        if (cell == 1) {
            if (d == 1)
                ans = findpath(grid, i, j + 1, 2, dp);
            else
                ans = findpath(grid, i + 1, j, 1, dp);
        } else {
            ans = findpath(grid, i, j + 1, 2, dp);
            ans = (ans + findpath(grid, i + 1, j, 1, dp)) % MOD;
        }

        return dp[i][j][d] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1))
        );

        return findpath(grid, 0, 0, 1, dp);
    }
};
