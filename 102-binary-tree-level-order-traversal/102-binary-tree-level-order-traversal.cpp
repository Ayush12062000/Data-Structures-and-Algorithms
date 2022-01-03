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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        res.push_back({root->val});
        
        while(!q.empty())
        {
            
            vector<int> levelnodes;
            int s = q.size();
     
            for(int i=0;i<s;i++)
            {
                TreeNode * node=q.front();
                q.pop();
                
                if(node->left) 
                {
                    q.push(node->left);
                    levelnodes.push_back(node->left->val);
                }
                if(node->right)
                {
                    q.push(node->right);
                    levelnodes.push_back(node->right->val);
                }
            }
            if(levelnodes.size()!=0)
                res.push_back(levelnodes);
        }
        return res;
    }
};