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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        queue<int> lq;
        
        q.push(root);
        lq.push(1);
        
        while(!q.empty()){
            
            int cur_level = lq.front();
            lq.pop();
            
            TreeNode* cur_node = q.front();
            int cur_val = cur_node->val;
            q.pop();
            //cout << "cur_level: " << cur_level << "  cur_val: " << cur_val << endl;
            if( ans.size() < cur_level ){
                vector<int> temp;
                ans.push_back(temp);
            }
            
            ans[cur_level - 1].push_back(cur_val);
            
            //if(cur_node->left != NULL || cur_node->right != NULL) level++;
            
            if(cur_node->left != NULL){
                q.push(cur_node->left);
                lq.push(cur_level + 1);
            }
            
            if(cur_node->right != NULL){
                q.push(cur_node->right);
                lq.push(cur_level + 1);
            }
        
        }
        
        return ans;
        
    }
};