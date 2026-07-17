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
    //tree dp, backtracking doesnt work bc we need optimal states from both scenarios, so we recursively get the scenario results
    pair<int, int> dfs(TreeNode* curr) { //return {result_if_skip, result_if_rob}
        if (!curr) return {0,0};
        //get values from children
        auto left = dfs(curr->left);
        auto right = dfs(curr->right);
        
        int rob = curr->val + left.first + right.first; //rob this house, so skip the children
        int skip = max(left.first, left.second) + max(right.first, right.second); //skip this house, take the best result from each child since we can rob both children
        return {skip, rob};
    }
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};