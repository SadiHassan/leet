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
    bool rec(TreeNode* root, int sum, int target){
        if(root == NULL) return false;
        if(sum == target && root->left == NULL && root->right == NULL) return true;       
        
        bool res1 = false, res2 = false;
        
        if(root->left != NULL)
            res1 = rec(root->left, sum + root->left->val, target);
        
        if(root->right != NULL)
            res2 = rec(root->right, sum + root->right->val, target);
        
        return res1 | res2;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root->val == sum && root->left == NULL && root->right == NULL) return true;
        return rec(root, root->val, sum);
    }
};