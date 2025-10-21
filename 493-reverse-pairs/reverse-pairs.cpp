class Solution {
public:
    void merge(vector<int>& nums, int start, int end, int mid, int& ans) {
        int j=mid+1;
        for(int i=start;i<=mid;i++){
            while(j<=end&&(long long)nums[i]>2LL*nums[j]){
                j++;
               
            }
            ans+=j-(mid+1);
        }
        vector<int> temp;
        int left = start, right = mid + 1;
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= end)
            temp.push_back(nums[right++]);

        for (int i = start; i <= end; ++i) {
            nums[i] = temp[i - start];
        }
    }

    void dc(vector<int>& nums, int start, int end, int& ans) {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        dc(nums, start, mid, ans);
        dc(nums, mid + 1, end, ans);
        merge(nums, start, end, mid, ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        dc(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};