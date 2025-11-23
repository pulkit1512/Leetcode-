class Solution {
public:
    bool find(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }

    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end()); // ensure binary search works
        int n = nums.size();
        while (find(nums, original, 0, n - 1)) {
            original *= 2;
        }
        return original;
    }
};
