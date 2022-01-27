class Solution {
public:
    
    void helper(TreeNode *root,string s, vector<string> &ans)
    {
        if(!root) return;
        
        if(s=="") s+=to_string(root->val);
        else s+="->"+to_string(root->val);
        
        if(!root->left && !root->right) {ans.push_back(s); s="";}
        
        helper(root->left,s,ans);
        helper(root->right,s,ans);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        string s;
        helper(root,s,ans);
        return ans;
        
    }
};
