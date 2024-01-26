/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    vector<int> help(TreeNode* root, int d){
        if(!root) return {0};
        if(!root->left && !root->right) return {1};

        auto left = help(root->left, d);
        auto right = help(root->right, d);

        for(auto &l: left){
            for(auto &r: right){
                if(l && r && l+r <= d) ans++;
            }
        }

        vector<int> res;
        for(auto &el: left){
            if(el && el+1 < d) res.push_back(el+1);
        }
        for(auto &el: right){
            if(el && el+1 < d) res.push_back(el+1);
        }

        return res;
    }


    int countPairs(TreeNode* root, int distance) {
        help(root, distance);
        return ans;
    }
};
