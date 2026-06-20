class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>>arr;
        arr.push_back({1,0});
        for(int i=0;i<restrictions.size();i++){
            arr.push_back(restrictions[i]);
        }

        arr.push_back({n,n-1});
        sort(arr.begin(),arr.end());
        int m=arr.size();

        for(int i=1;i<m;i++){
            int d = arr[i][0]-arr[i-1][0];
            arr[i][1]=min(arr[i][1],d+arr[i-1][1]);
        }
        for(int i=m-2;i>=0;i--){
            int d=arr[i+1][0]-arr[i][0];
            arr[i][1]=min(arr[i][1],d+arr[i+1][1]);
        }
        int ans=0;
        for(int i=1;i<m;i++){
            int d=arr[i][0]-arr[i-1][0];
            ans=max(ans,(d+arr[i][1]+arr[i-1][1])/2);
        }
        return ans;
    }
};