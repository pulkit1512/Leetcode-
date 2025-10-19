class Solution {
public:
    bool isPowerOfFour(int n) {
        int x=n;
        if(n<0||n==0) return 0;
        long long ans=1;
        while(ans<=n){
            if(ans==x) return 1;
            ans=ans*4;
            
            
        }
        return 0;
    }
};