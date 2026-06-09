class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans =INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int x1=landStartTime[i]+landDuration[i];
                int y1=max(x1,waterStartTime[j]);
                int z1=y1+waterDuration[j];

                int x2=waterStartTime[j]+waterDuration[j];
                int y2=max(x2,landStartTime[i]);
                int z2=y2+landDuration[i];
                ans=min({ans,z1,z2});
            }
        }
        return ans;
    }
};