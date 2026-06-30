class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merge;

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 0) return {};

        merge.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            int lastIdx = merge.size() - 1;
            if(intervals[i][0] <= merge[lastIdx][1]){
                merge[lastIdx][1] = max(merge[lastIdx][1], intervals[i][1]);
            }
            else{
                merge.push_back(intervals[i]);
            }
        }
        return merge;
    }
};