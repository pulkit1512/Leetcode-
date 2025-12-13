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
    TreeNode*helper(vector<int>&nums,int start,int end){
        if(start>end) return NULL;
        TreeNode*root=NULL;
        
        int maxi=INT_MIN;
        int index=start;
        for(int i=start;i<=end;i++){
           if(maxi<nums[i]){
            maxi=nums[i];
            index=i;
           }
        }
        root=new TreeNode(maxi);
        root->left=helper(nums,start,index-1);
        root->right=helper(nums,index+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};