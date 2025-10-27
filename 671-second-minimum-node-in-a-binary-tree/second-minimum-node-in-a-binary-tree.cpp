class Solution {
public:
    void helper(TreeNode* root, int& first_min) {
        if (!root) return;
        first_min = min(first_min, root->val);
        helper(root->left, first_min);
        helper(root->right, first_min);
    }

    void helper1(TreeNode* root, int first_min, long long& second_min) {
        if (!root) return;
        if (root->val > first_min) {
            second_min = min(second_min, (long long)root->val);
        }
        helper1(root->left, first_min, second_min);
        helper1(root->right, first_min, second_min);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int first_min = INT_MAX;
        helper(root, first_min);

        long long second_min = LLONG_MAX;
        helper1(root, first_min, second_min);

        return second_min == LLONG_MAX ? -1 : (int)second_min;
    }
};
