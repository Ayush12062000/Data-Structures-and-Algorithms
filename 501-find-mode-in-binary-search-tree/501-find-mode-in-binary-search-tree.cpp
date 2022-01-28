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
    void util(TreeNode* root,unordered_map<int,int> &m)
    {
        if(root==NULL) return ;
        m[root->val]++;
        util(root->left,m);
        util(root->right,m);
    }
    
    
    vector<int> findMode(TreeNode* root) {
      
        vector<int> ans;
        
        unordered_map<int,int> m;
        
        util(root,m);
        int maxi = INT_MIN;
        for(auto &i:m)
        {
            if(i.second>maxi)
            {
                ans.clear();
                maxi=i.second;
                ans.push_back(i.first);
            } 
            else if (i.second==maxi)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};