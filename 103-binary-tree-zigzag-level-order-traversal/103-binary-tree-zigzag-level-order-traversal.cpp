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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LeftToRight=true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(LeftToRight)
            {
                ans.push_back(temp);
                for(int i=0;i<temp.size();i++)
                    cout<<temp[i]<<" ";
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                for(int i=0;i<temp.size();i++)
                    cout<<temp[i]<<" ";
            }
            LeftToRight=!LeftToRight;
        }
        return ans;
    }
};