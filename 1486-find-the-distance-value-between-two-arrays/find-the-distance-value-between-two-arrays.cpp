class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int x = arr1[i];
            int start = 0, end = arr2.size() - 1;
            int closest = arr2[0];

            while(start<=end) {
                int mid = start + (end - start) / 2;

                if (abs(arr2[mid] - x) < abs(closest - x)) {
                    closest = arr2[mid];
                }

                if (arr2[mid] < x) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            if (abs(x - closest) > d)
                ans++;
        }

        return ans;
    }
};