class Solution {
public:
    bool isPowerOfThree(int n) {
//         3^{19} = 1162261467
// So if n is a power of 3, it must divide 1162261467 exactly

        return n > 0 && 1162261467 % n == 0;
        
    }
};
