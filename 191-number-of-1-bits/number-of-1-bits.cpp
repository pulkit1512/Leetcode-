class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        string num="";
        while(n){
            char c=n%2+'0';
            num=num+c;
            n/=2;
        }
        for(int i=0;i<num.length();i++){
            if(num[i]=='1') ans++;
        }
        return ans;
    }
};