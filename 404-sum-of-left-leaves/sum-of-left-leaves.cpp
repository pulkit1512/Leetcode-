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
    void helper(TreeNode*root,int &ans,bool isflag){
        if(!root) return ;
       
        helper(root->right,ans,false);
    
        helper(root->left,ans,true);
        if(!root->left&&!root->right&&isflag) ans+=root->val;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        bool isflag=0;
         if(!root->left&&!root->right) return 0;
        helper(root,ans,isflag);
        return ans;
    }
};