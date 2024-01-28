class Solution {
public:
    int vis[35][35];
    int n,m;

    void dfs(int i,int j, vector<vector<int>>& grid){
        vis[i][j] = 1;
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1) dfs(i-1, j, grid);
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1) dfs(i+1, j, grid);
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1) dfs(i, j-1, grid);
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1) dfs(i, j+1, grid);
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(vis,0,sizeof(vis));

        //no of islands
        int island = 0;
        int ones = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,grid);
                    island++;
                }
                if(grid[i][j]) ones++;
            }
        }

        if(island > 1 || island == 0) return 0;
        
        if(n == 1 || m == 1 || ones <= 2) return ones == 2 ? 2 : 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    memset(vis,0,sizeof(vis));

                    int isd = 0;
                    for(int k=0;k<n;k++){
                        for(int l=0;l<m;l++){
                            if(!vis[k][l] && grid[k][l]){
                                isd++;
                                dfs(k, l, grid);
                            }
                        }
                    }
                    if(isd > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};
