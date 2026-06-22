class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int ans=0;
        bool sign =true;
        while(i<s.size()&&s[i]==' ') i++;
        if(i==s.size()) return 0;

        if(s[i]=='-'){
            sign=false;
            i++;
        }
        else if(s[i]=='+'){
            sign=true;
            i++;
        }
        while(i<s.size()&&isdigit(s[i])){
            int temp=s[i]-'0';
            if(ans>(INT_MAX-temp)/10){
                return sign?INT_MAX:INT_MIN;
            }
            ans=ans*10+temp;
            i++;
        }
        if(!sign) ans=-ans;
        return ans ;
    }
};