class Solution {
public:
    int numberOfSubstrings(string s) {
        int count1=0,count2=0,count3=0;
        int first=0,second=0;
        int total=0;
        while(second<s.size()){
            if(s[second]=='a') count1++;
            else if(s[second]=='b') count2++;
            else if(s[second]=='c') count3++;
            while(count1>0&&count2>0&&count3>0&&first<=second){
                total+=s.size()-second;
                if(s[first]=='a') count1--;
                else if(s[first]=='b') count2--;
                else if(s[first]=='c') count3--;
                first++;
            }
            second++;
        }
        return total;
    }
};