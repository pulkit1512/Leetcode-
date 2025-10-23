class Solution {
public:
    void dfs(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        dfs(node->left, vals);
        vals.push_back(node->val);
        dfs(node->right, vals);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> vals;
        dfs(root, vals);
        vector<vector<int>> res;

        for (int i = 0; i < q.size(); i++) {
            int x = q[i], lo = 0, hi = vals.size() - 1, fl = -1, cl = -1;

            while (lo <= hi) {
                int m = lo + (hi - lo) / 2;
                if (vals[m] <= x) {
                    fl = vals[m];
                    lo = m + 1;
                } else {
                    hi = m - 1;
                }
            }

            lo = 0, hi = vals.size() - 1;
            while (lo <= hi) {
                int m = lo + (hi - lo) / 2;
                if (vals[m] >= x) {
                    cl = vals[m];
                    hi = m - 1;
                } else {
                    lo = m + 1;
                }
            }

            res.push_back({fl, cl});
        }

        return res;
    }
};
