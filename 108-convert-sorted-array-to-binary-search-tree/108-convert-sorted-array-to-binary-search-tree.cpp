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
    TreeNode* insertintotree(vector<int> &nums,int l,int h)
    {
        if(l<=h)
        {
            int mid = l+(h-l)/2;
            TreeNode* newnode = new TreeNode(nums[mid]);
            newnode->left = insertintotree(nums,l,mid-1);
            newnode->right = insertintotree(nums,mid+1,h);
            return newnode;
        }
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        TreeNode* root = insertintotree(nums,l,h);
        return root;
    }
};