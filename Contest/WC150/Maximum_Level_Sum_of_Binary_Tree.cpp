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
    int level[10000];
    void init(){
        for(int i = 0; i < 10000; i++) level[i] = 0;
    }
    
    void rec(TreeNode* root, int lev){
        if(root == NULL) return;
        level[lev] += root->val;
        rec(root->left, lev+1);
        rec(root->right, lev+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        rec(root, 1);
        int sum = 0;
        int ans = 1;
        for(int i = 0; i < 10000; i++){
            if(sum < level[i]){
                sum = level[i];
                ans = i;
            }
        }
        return ans;
    }
};