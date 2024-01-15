class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    cnt++;
                    int k = j;
                    while(k<m && board[i][k] == 'X'){
                        vis[i][k] = 1;
                        k++;
                    }
                    k = i;
                    while(k<n && board[k][j] == 'X'){
                        vis[k][j] = 1;
                        k++;
                    }
                }
            }
        }

        return cnt;
    }
};
