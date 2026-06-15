class Solution {
public:
    int bitwiseComplement(int n) {
        int rem;
        int ans=0;
        int mul=1;
        if(n==0) return 1;
        while(n){
            rem=n%2;
            rem=rem^1;
            ans+=rem*mul;
            mul*=2;
            n=n/2;
        }
        return ans;
    }
};