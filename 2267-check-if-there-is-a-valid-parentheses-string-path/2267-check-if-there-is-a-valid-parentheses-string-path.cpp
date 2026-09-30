class Solution {
public:
    bool findpath(vector<vector<char>>& grid, int i, int j, int b, vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (i >= m || j >= n) {
            return false;
        }
         int originalB = b;

         // Already calculated
        if (dp[i][j][b] != -1) {
            return dp[i][j][b];
        }

        // Update balance
        if (grid[i][j] == '(') {
            b++;
        } 
        else {
            b--;
        }

        // Invalid balance
        if (b < 0) {
            return false;
        }

        // Last cell
        if (i == m - 1 && j == n - 1) {
            return b == 0;
        }

        // Two choices
        bool right = findpath(grid, i, j + 1, b,dp);
        bool down = findpath(grid, i + 1, j, b,dp);

         return dp[i][j][originalB] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
          vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );
        return findpath(grid, 0, 0, 0,dp);
    }
};