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
    
    bool equals(TreeNode* x, TreeNode* y){
        if(x == nullptr && y == nullptr) return true;
        if(x == nullptr || y == nullptr) return false;
        return x->val == y->val && equals(x->left, y->left) && equals(x->right, y->right);
    }
    
    bool traverse(TreeNode* s, TreeNode* t){
        return ( s != nullptr && ( equals(s, t) || traverse(s->left, t) || 
                              traverse(s->right, t) ) );
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s, t);    
    }
};