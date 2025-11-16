class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int count_a=0;
        int count_b=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a') count_a++;
            else count_b++;
        }
        return abs(count_a-count_b);
    }
};