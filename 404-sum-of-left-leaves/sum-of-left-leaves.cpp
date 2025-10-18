class Solution {
public:
    void helper(TreeNode* root, int& ans, int flag) {
        if (!root) return;
        if (!root->left && !root->right && flag == 1) {
            ans += root->val;
        }
        helper(root->left, ans, 1);  
        helper(root->right, ans, 0); 
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        // use a variable flag so when we at left it is 1 and when we at right it is 0 
       
        helper(root, ans, 0);
        return ans;
    }
};
