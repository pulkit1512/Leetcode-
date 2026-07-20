class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int buy = arr[0];
        int profit = 0;
        for (int i = 0; i < n; i++) {
            if (buy >= arr[i]) {
                buy = arr[i];
            }
            profit = max(profit, arr[i] - buy);
        }

        return profit;
    }
};