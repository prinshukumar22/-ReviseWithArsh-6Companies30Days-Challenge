class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int ko) {
        //floyd warshall algo lagao
        vector<vector<long long>> adj(n, vector<long long>(n, INT_MAX));

        for(auto &el: edges){
            int u = el[0];
            int v = el[1];
            long long w = (long long)el[2];

            adj[u][v] = min(adj[u][v] , w);
            adj[v][u] = min(adj[v][u] , w);
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = min(adj[i][j] , (long long)adj[i][k]+(long long)adj[k][j]);
                }
            }
        }

        int cnt;
        int mini = INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
            cnt = 0;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(adj[i][j] <= ko){
                    cnt++;
                }
            }

            if(cnt <= mini){
                mini = cnt;
                ans = i;
            }
        }

        return ans;
    }
};
