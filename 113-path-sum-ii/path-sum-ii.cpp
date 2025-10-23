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
    void helper(TreeNode*root,int targetSum,vector<vector<int>>&ans,int &sum,vector<int>&temp){
        if(!root) return ;
        temp.push_back(root->val);
        sum+=root->val;
        if(!root->left&&!root->right&&sum==targetSum){
            ans.push_back(temp);
        }
        helper(root->left,targetSum,ans,sum,temp);
        helper(root->right,targetSum,ans,sum,temp);
         // Backtrack after exploring both children
         // in previous code we do the early backtrack so the ans array always remains empty
        temp.pop_back();
        sum -= root->val;


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        helper(root,targetSum,ans,sum,temp);
        return ans;
    }
};