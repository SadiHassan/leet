/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    void rec(TreeNode* root, int depth){
        if(root->left == NULL && root->right == NULL){
            ans = min(ans, depth);
            return;
        }
        if(root->left != NULL) rec(root->left, depth + 1);
        if(root->right != NULL) rec(root->right, depth + 1);
        return;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        ans = INT_MAX;
        rec(root, 1);
        return ans;
    }
};