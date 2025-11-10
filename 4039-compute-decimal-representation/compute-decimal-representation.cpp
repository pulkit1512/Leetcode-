class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        vector<int>arr;
        while(n){
            int x=n%10;
            arr.push_back(x);
            n=n/10;
        }
        int z=arr.size();
        for(int i=0;i<z;i++){
            int y=pow(10,i);
            if(arr[i]!=0){
            ans.push_back(arr[i]*y);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};