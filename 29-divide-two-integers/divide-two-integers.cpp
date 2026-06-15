class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign=true;
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        long long n=dividend;
        n=llabs(n);
        long long d=divisor;
        long long ans=0;
        d=llabs(d);
        if(dividend>=0&&divisor<0) sign = false;
        if(dividend<=0&&divisor>0) sign = false;
        while(n>=d){
            int count =0;
            while(d<<(count+1)<=n){
                count++;
            }
            ans+=1<<count;
            n-=d<<count;
        }
        if(ans>=(INT_MAX)&&sign==true) return INT_MAX;
        if(ans>(INT_MAX)&&sign==false) return INT_MIN;
        return sign?ans:(-ans);
    }
};