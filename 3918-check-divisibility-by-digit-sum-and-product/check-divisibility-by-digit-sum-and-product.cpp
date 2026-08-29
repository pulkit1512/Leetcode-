class Solution {
public:
    bool checkDivisibility(int n) {
        int count=0;
        int product=1;
        int y=n;
        while(n){
          int x=n%10;
          count+=x;
          product*=x;
          n/=10;
        }
        if(y%(count+product)==0) return 1;
        return 0;
    }
};