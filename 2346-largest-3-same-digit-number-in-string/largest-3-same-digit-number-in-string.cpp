class Solution {
public:
    string largestGoodInteger(string nums) {
        string str = "";
        int max_good = -1;

        for (int i = 0; i <= nums.length() - 3; i++) {
            if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                int x = nums[i] - '0';
                if (x > max_good) {
                    str = nums.substr(i, 3);
                    max_good = x;
                }
            }
        }

        return str;
    }
};
