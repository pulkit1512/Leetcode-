class Solution {
public:
    void helper(vector<int>& candidates, int target, int sum, int index,
                vector<int>& temp, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target || index == candidates.size())
            return;

        temp.push_back(candidates[index]);
        helper(candidates, target, sum + candidates[index], index + 1, temp,
               ans);
        temp.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < candidates.size() &&
               candidates[nextIndex] == candidates[index]) {
            nextIndex++;
        }
        helper(candidates, target, sum, nextIndex, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, temp, ans);
        return ans;
    }
};
