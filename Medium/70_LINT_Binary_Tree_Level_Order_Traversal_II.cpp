/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        // write your code here
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> temp_arr;
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) continue;
            
            temp_arr.push_back(temp->val);
            
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            
            if(q.front() == NULL) { 
                ans.push_back(temp_arr); 
                temp_arr.clear();
                q.push(NULL);
            }
        }
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};