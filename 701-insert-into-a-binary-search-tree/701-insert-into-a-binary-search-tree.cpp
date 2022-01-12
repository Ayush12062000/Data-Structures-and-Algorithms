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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newnode = new TreeNode(val);
        if(root==NULL)
            return newnode;
        TreeNode *prev,*cur;
        cur = root;
        while(cur!=NULL)
        {
            prev = cur;
            cur = (val < cur->val) ? cur->left : cur->right;
        }
        if(val<prev->val)
            prev->left = newnode;
        else
            prev->right = newnode;
        return root;
    }
};