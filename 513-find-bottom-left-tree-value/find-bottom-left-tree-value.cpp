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
int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
void dfs(TreeNode* node, int depth, int height, int &ans, bool &found) {
    if (!node || found) return;

    if (depth == height) {
        ans = node->val;
        found = true; 
        return;
    }

    dfs(node->left, depth + 1, height, ans, found);
    dfs(node->right, depth + 1, height, ans, found);
}

int findBottomLeftValue(TreeNode* root) {
    int height = getHeight(root);
    int ans = -1;
    bool found = false;
    dfs(root, 1, height,ans, found);
    return ans;
}
};