class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,bool>m;
        for(int i=0;i<jewels.size();i++){
            m[jewels[i]]=1;
        }
        int count=0;
        for(int i=0;i<stones.size();i++){
            if(m[stones[i]]) count++;
        }
        return count;
    }
};