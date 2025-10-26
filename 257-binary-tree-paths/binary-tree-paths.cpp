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
void helper(TreeNode*root,vector<string>&ans,string str){
    if(!root) return ;
    if(!str.empty())str+="->";
    str+=to_string(root->val);
    if(!root->left&&!root->right){
        ans.push_back(str);
    }
    helper(root->left,ans,str);
    helper(root->right,ans,str);

    str.pop_back();

}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str="";
        helper(root,ans,str);
        return ans;
    }
};