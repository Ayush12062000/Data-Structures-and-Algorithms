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
    int val=INT_MAX,mini=INT_MAX;
    int inorder(TreeNode* root)
    {
        if(!root) return 0;
        inorder(root->left);
        if(val<INT_MAX) mini = min(mini,root->val-val);
        val = root->val;
        inorder(root->right);
        return mini;
    }
    
    int getMinimumDifference(TreeNode* root) {
        return inorder(root);
    }
};