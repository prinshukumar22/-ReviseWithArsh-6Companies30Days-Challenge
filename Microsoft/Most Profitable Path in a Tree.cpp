class Solution {
public:
    int dfs2(int src, int cnt, vector<int> &ttrn, unordered_map<int,vector<int>> &adj, vector<int>& amt, unordered_map<int,bool> &vis){
        vis[src] = 1;
        int a=INT_MIN;
        int f=0;
        for(auto &neigh: adj[src]){
            if(!vis[neigh]){
                f=1;
                if(ttrn[src] > cnt || ttrn[src] == -1){
                    int c=dfs2(neigh, cnt+1, ttrn, adj, amt,vis);
                    if(c!=INT_MIN)
                    {
                    a = max(a, amt[src] + c);
                    }
                }
                else if(ttrn[src] == cnt){
                    int c=dfs2(neigh, cnt+1, ttrn, adj, amt,vis);
                    if(c!=INT_MIN)
                    {
                    a = max(a, amt[src]/2 + c);
                    }
                    //a = max(a, amt[src]/2 + dfs2(neigh, cnt+1, ttrn, adj, amt,vis));
                }
                    
                else{
                     int c=dfs2(neigh, cnt+1, ttrn, adj, amt,vis);
                    if(c!=INT_MIN)
                    {
                    a = max(a, c);
                    }
                    //a = max(a, dfs2(neigh, cnt+1, ttrn, adj, amt,vis));
                }
            }
        }
         if(f==0)
         {
             if(ttrn[src]==cnt)
             {
                 return amt[src]/2;
             }
             else if(ttrn[src]<cnt && ttrn[src]!=-1)
             {
                 return 0;
             }
             return amt[src];
         }
        return a;
    }

    void dfs(int src, unordered_map<int,vector<int>> &adj, unordered_map<int,int> &parent, unordered_map<int,bool> &vis){
        vis[src] = 1;
        for(auto &ne: adj[src]){
            if(!vis[ne]){
                parent[ne] = src;
                dfs(ne, adj, parent, vis);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        int n = edges.size() + 1;
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> parent;
        vector<int> ttrn(n,-1);
        int stepcnt = 0;
        for(auto &el: edges){
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
        }

        parent[0] = -1;
        unordered_map<int,bool> vis;
        dfs(0, adj, parent, vis);

        // for(auto &el: parent){
        //     cout<<el.first<<" "<<el.second<<endl;
        // }

        int src = bob;
        ttrn[src] = 0;
        while(parent[src] != -1){
            src = parent[src];
            stepcnt++;
            ttrn[src] = stepcnt;
        }

        // for(auto &el: ttrn){
        //     cout<<el<<endl;
        // }

        unordered_map<int,bool> vis2;
        return dfs2(0,0,ttrn,adj, amt, vis2);
    }
};
