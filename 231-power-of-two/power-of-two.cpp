class Solution {
public:
    bool isPowerOfTwo(int n) {
         int x=n;
         long long  ans=1;
         while(ans<=n){
            if(ans==n) return true;
            ans=ans*2;
            
         }
         return false;
    }
};