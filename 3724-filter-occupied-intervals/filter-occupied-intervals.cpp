class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        vector<vector<int>> merge;

        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        int n = occupiedIntervals.size();
        if (n == 0) return ans;

        merge.push_back(occupiedIntervals[0]);

        for(int i = 1; i < n; i++){
            int lastIdx = merge.size() - 1;
            if(occupiedIntervals[i][0] <= merge[lastIdx][1] + 1){
                merge[lastIdx][1] = max(merge[lastIdx][1], occupiedIntervals[i][1]);
            }
            else{
                merge.push_back(occupiedIntervals[i]);
            }
        }

        for(int i = 0; i < merge.size(); i++){
            if(merge[i][0] >= freeStart && merge[i][1] <= freeEnd) {
                continue;
            }
            else if(merge[i][0] >= freeStart) {
                ans.push_back({max(merge[i][0], freeEnd + 1), merge[i][1]});
            }
            else if(merge[i][1] <= freeEnd) {
                ans.push_back({merge[i][0], min(merge[i][1], freeStart - 1)});
            }
            else if(merge[i][0] < freeStart && merge[i][1] > freeEnd) {
                ans.push_back({merge[i][0], freeStart - 1});
                ans.push_back({freeEnd + 1, merge[i][1]});
            }
            else{
                ans.push_back(merge[i]);
            }
        }
        return ans;
    }
};