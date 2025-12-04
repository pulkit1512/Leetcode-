class Solution {
public:
    void helper(vector<int>& candidates, int &target, int index, vector<int> &temp, int sum, vector<vector<int>> &ans) {
        if (sum>target || index>=candidates.size()) return;
        if (sum==target) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[index]);
        helper(candidates, target, index, temp, sum+candidates[index], ans);
        temp.pop_back();
        helper(candidates, target, index+1, temp, sum, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, 0, temp, 0, ans);
        return ans;
    }
};