class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // we check if the target[i]>target[i-1] then we need target[i]-target[i-1] extra operation to else if it is not than it is covered already
        int operations = target[0];
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        return operations;
    }
};