class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>&ans){
        int sum=0;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        int count=0;
        int i=0;
        while(sum>0){
            sum=sum-ans[i];
            i++;
            count++;
        }
        return count;
    }
};