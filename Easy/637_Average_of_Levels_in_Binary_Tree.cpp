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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL) return ans;
        
        vector<double> temp_arr;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) continue;
            
            temp_arr.push_back((double)temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(q.front() == NULL){
                q.push(NULL);
                double avg = 0;
                double len = temp_arr.size();
                for(int i = 0; i < temp_arr.size(); i++) avg += temp_arr[i];
                avg = avg / len;
                ans.push_back(avg);
                temp_arr.clear();
            }
        }
        
        return ans;
    }
};