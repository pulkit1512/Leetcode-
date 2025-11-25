class Solution {
public:
    bool bst(TreeNode* root, long &prev) {
        if (!root) {
            return true;
        }

        bool left = bst(root->left, prev);
        if (root->val <= prev) {
            return false;
        }
        
        prev = root->val;
        bool right = bst(root->right, prev);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN; 
        return bst(root, prev);
    }
};
