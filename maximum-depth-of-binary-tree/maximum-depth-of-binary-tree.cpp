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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
};

/*
using bfs solution

class Solution {
public:
    int bfs(TreeNode* root)
    {
        int height=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            height++;
            for(int i=0;i<s;i++)
            {
                TreeNode * node=q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return height;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return bfs(root);
    }
};
*/
