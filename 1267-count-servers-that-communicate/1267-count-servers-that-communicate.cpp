class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
       set<pair<int,int>>s;

       int m = grid.size();
       int n = grid[0].size();

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                bool found = false;
                // check columns
                for(int k=j+1;k<n;k++){
                    if(grid[i][k]==1){
                        found=true;
                        s.insert({i,k});
                    }
                }
                // row check
                 for(int p=i+1;p<m;p++){
                    if(grid[p][j]==1){
                        found=true;
                        s.insert({p,j});
                    }
                }
                if(found){
                    s.insert({i,j});
                }
                
            }
        }
       }
       return s.size();
    }
};