class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="";
        vector<int>weight;
        for(int i=0;i<words.size();i++){
            int x=0;
            for(int j=0;j<words[i].length();j++){
                x+=weights[words[i][j]-'a'];
            }
            ans+='z'-x%26;
        }
        return ans;
    }
};