class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = 0, second = 0;
        int count1 = 0, count2 = 0;
        int x = -1, y = -1; // Track the two distinct fruit types
        int ans = 0;

        while (second < fruits.size()) {
            int current = fruits[second];

            if (current == x) {
                count1++;
            } else if (current == y) {
                count2++;
            } else if (count1 == 0) { 
                x = current;
                count1 = 1;
            } else if (count2 == 0) { 
                y = current;
                count2 = 1;
            } else {

                while (count1 > 0 && count2 > 0) {
                    if (fruits[first] == x) {
                        count1--;
                    } else if (fruits[first] == y) {
                        count2--;
                    }
                    first++;
                }

                if (count1 == 0) {
                    x = current;
                    count1 = 1;
                } else {
                    y = current;
                    count2 = 1;
                }
            }

            ans = max(ans, count1 + count2);
            second++;
        }

        return ans;
    }
};