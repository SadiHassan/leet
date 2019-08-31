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
    vector<vector<int>> ans;
    vector<int> arr;
    void rec(TreeNode* root, int sum, int sum_so_far){
        if(sum_so_far + root->val == sum && 
           root->left == NULL &&
           root->right == NULL) {
            arr.push_back(root->val);
            ans.push_back(arr);
            arr.pop_back();
            return;
        }
        
        if(root->left != NULL){
            arr.push_back(root->val);
            rec(root->left, sum, sum_so_far + (root->val));
            arr.pop_back();
        }
        
        if(root->right != NULL){
            arr.push_back(root->val);
            rec(root->right, sum, sum_so_far + (root->val) );
            arr.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return ans;
        rec(root, sum, 0);
        return ans;
    }
};