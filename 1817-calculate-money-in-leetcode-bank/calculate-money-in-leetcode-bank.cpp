class Solution {
public:
    int totalMoney(int n) {
        int x=n/7;
        int y=n%7;
        int sum=0;
        for(int i=0;i<x;i++){
            sum+=(7*(2*(i+1)+6))/2;
        }
        for(int i=0;i<y;i++){
            sum+=x+1+i;
        }
        return sum;
    }
};