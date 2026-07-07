class Solution {
public:
    long long sumAndMultiply(int n) {
        long long  sum=0;
        long long  temp=0;
        while(n!=0){
            int x=n%10;
            if(x!=0){
            temp=temp*10+x;
            }
            n/=10;
            sum+=x;
        }
        long long temp2=0;
        while(temp!=0){
            temp2=temp2*10+temp%10;
            temp/=10;
        }
        return temp2*sum;
    }
};