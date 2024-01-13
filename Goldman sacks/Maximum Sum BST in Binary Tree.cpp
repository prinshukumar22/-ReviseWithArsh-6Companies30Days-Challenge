class Solution {
public:
    vector<int> solve(TreeNode* root, int &sum){
        if(!root){
            return {true, 0, INT_MAX, INT_MIN};
        }

        int a = root->val;
        if(!root->left && !root->right){
            sum = max(sum, a);
            return {true, a, a, a};
        }

        auto left = solve(root->left, sum);
        auto right = solve(root->right, sum);

        if(left[0] && right[0] && root->val < right[2] && left[3] < root->val){
            int s = root->val + left[1] + right[1];
            sum = max(s, sum);
            return {true, s, min(a, min(left[2], right[2])), max(a, max(left[3], right[3]))};
        }

        return {false, 0, INT_MAX, INT_MIN};
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;

        solve(root, sum);

        return sum;
    }
};
