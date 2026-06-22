class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int>m;
        for(int i=0;i<text.size();i++){
            m[text[i]]++;
        }
        return min({m['b'],m['a'],m['l']/2,m['o']/2,m['n']});

    }
};