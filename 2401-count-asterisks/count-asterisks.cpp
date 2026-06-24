class Solution {
public:
    int countAsterisks(string s) {
        bool isPair=false;
        int count =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'&&!isPair) isPair=true;
            else if(s[i]=='|'&&isPair) isPair=false;
            if(s[i]=='*'&&!isPair) count++;
        }
        return count;
    }
};