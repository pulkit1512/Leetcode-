class Solution {
    static const long long MOD = 1000000007;

public:
    void helper(long long &n,long long &x,long long &result){
        if(n==0) return;
        if(n%2==0){
            x = (x * x) % MOD;       // apply modulus here
            n /= 2;
            helper(n,x,result);
        }
        else{
            result = (result * x) % MOD; // apply modulus here
            n--;
            helper(n,x,result);
        }
    }

    long long mypow(long long x,long long n){
        long long result = 1;
        helper(n,x,result);
        return result % MOD;
    }

    int countGoodNumbers(long long n) {
        return (mypow(5,(n+1)/2) * mypow(4,n/2)) % MOD;
    }
};
