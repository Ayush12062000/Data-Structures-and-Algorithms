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
    
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        if(isBalanced(root->left)==false) return false;
        if(isBalanced(root->right)==false) return false;
        
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)<=1) return true;
        else return false;
    }
};