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
    void helper(TreeNode*root,int&sum,string&s){
        if(!root) return ;
        s+=root->val+'0';
        if(!root->left&&!root->right){
          int number = std::stoi(s, nullptr, 2);
          sum+=number;
        }
        helper(root->left,sum,s);
        helper(root->right,sum,s);
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        string s="";
        helper(root,sum,s);
        return sum;
    }
};