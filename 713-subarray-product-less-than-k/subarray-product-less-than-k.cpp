class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int first = 0;
        int second = 0;
        int count = 0;
        int product = 1;
        while (second < nums.size()) {
            product *= nums[second];
            if (product < k) {
                count += (second - first + 1);
            } else {
                while (product >= k&&first<nums.size()) {
                    product /= nums[first];
                    first++;

                    if (product < k) {
                        count += (second - first + 1);
                    }
                }
            }
            second++;
        }
        return count;
    }
};