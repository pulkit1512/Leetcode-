class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n; 
        long long  first=1;
        long long second=1;
        long long  third;
        for(int i=2;i<=n;i++){
            third=first+second;
            first=second;
            second=third;
        }
        return third ;

    }
};