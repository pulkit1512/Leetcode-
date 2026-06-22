class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<int,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        unordered_map<int,int>m2;
        for(int i=0;i<target.size();i++){
            m2[target[i]]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<target.size();i++){
            ans=min(ans,m[target[i]]/m2[target[i]]);
        }
        return ans;
    }
};