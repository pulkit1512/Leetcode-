class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, r = 0, l = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'U') {
                u++;
            }
            if (moves[i] == 'D') {
                d++;
            }
            if (moves[i] == 'R') {
                r++;
            }
            if (moves[i] == 'L') {
                l++;
            }
        }
        return (u == d) && (l == r);
    }
};
