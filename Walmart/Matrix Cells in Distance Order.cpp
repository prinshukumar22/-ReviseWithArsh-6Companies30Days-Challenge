class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        vector<vector<int>> ans;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        queue<vector<int>> q;
        vis[r][c] = 1;
        q.push({r,c});

        while(!q.empty()){
            auto coor = q.front();
            int x = coor[0];
            int y = coor[1];
            q.pop();

            ans.push_back(coor);

            if(y+1 < cols && !vis[x][y+1]){
                vis[x][y+1] = 1;
                q.push({x,y+1});
            }
            if(y-1 >= 0 && !vis[x][y-1]){
                vis[x][y-1] = 1;
                q.push({x,y-1});
            }
            if(x+1 < rows && !vis[x+1][y]){
                vis[x+1][y] = 1;
                q.push({x+1,y});
            }
            if(x-1 >= 0 && !vis[x-1][y]){
                vis[x-1][y] = 1;
                q.push({x-1,y});
            }
        }

        return ans;
    }
};
