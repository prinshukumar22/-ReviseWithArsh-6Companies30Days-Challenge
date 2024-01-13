class Solution {
public:
    void solve(TreeNode* root, TreeNode* parent, unordered_map<TreeNode* , vector<TreeNode*>> &adj, TreeNode* &st, int &start){
        if(!root) return;
        if(root->val == start) st = root;

        adj[root] = {parent, root->left, root->right};
        solve(root->left, root, adj, st, start);
        solve(root->right, root, adj, st, start);
    }

    void bfs(TreeNode* start, unordered_map<TreeNode* , vector<TreeNode*>> &adj, unordered_map<TreeNode* , bool> &infec, int &cnt){
        queue<pair<TreeNode*, int>> q;
        q.push({start, 0});
        infec[start] = 1;

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            auto root = p.first;
            int time = p.second;
            //cout<<time<<endl;

            cnt = max(cnt, time);

            for(auto node: adj[root]){
                if(node && !infec[node]){
                    infec[node] = 1;
                    q.push({node, time+1});
                }
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* st = NULL;
        unordered_map<TreeNode* , vector<TreeNode*>> adj;
        unordered_map<TreeNode* , bool> infec;

        solve(root, NULL, adj, st, start);

        //cout<<st->val;

        int cnt = 0;
        bfs(st, adj, infec, cnt);

        return cnt;
    }
};
