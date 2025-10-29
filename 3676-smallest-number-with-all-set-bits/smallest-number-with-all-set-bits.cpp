class Solution {
public:
    int smallestNumber(int n) {
        int ans;
        for(int i=0;i<=10;i++){
            if(pow(2,i)-1>=n){
                ans=pow(2,i)-1;
                break;
            }
        }
        return ans;
    }
};