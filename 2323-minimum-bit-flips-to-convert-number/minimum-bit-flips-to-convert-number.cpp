class Solution {
public:
    string helper(int n){
        string s;
        while(n){
            int x=n%2;
            s.push_back('0'+x);
            n=n/2;
        }
        while(s.length()<32){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int minBitFlips(int x, int y) {
        string str1 =helper(x);
        string str2=helper(y);
        int i=0,j=0;
        int ans=0;
        while(i<32){
            if(str1[i]!=str2[j]){
                ans++;
            }
            i++,j++;
        }
        return ans;
    }
};