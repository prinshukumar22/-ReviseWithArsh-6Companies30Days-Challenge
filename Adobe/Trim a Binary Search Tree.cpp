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
    TreeNode* solveLow(TreeNode* root, int &low){
        if(!root) return root;
        if(root->val == low){
            root->left = NULL;
            return root;
        }
        if(root->val < low) return solveLow(root->right, low);

        root->left = solveLow(root->left, low);

        return root;
    }

    TreeNode* solveHigh(TreeNode* root, int &high){
        if(!root) return root;
        if(root->val == high){
            root->right = NULL;
            return root;
        }
        if(root->val > high) return solveHigh(root->left, high);

        root->right = solveHigh(root->right, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = solveLow(root, low);
        root = solveHigh(root, high);

        return root;
    }
};
