class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=1&&i==0){
                arr[i]=1;
            }
            else if(i>0&&abs(arr[i] - arr[i - 1]) > 1){
            arr[i]=arr[i-1]+1;
            }
            ans=max(ans,arr[i]);
        }
        return ans;
    }
};