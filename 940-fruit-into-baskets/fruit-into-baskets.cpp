class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = 0, second = 0;
        int count1 = 0, count2 = 0;
        int x = -1, y = -1;
        int count = 0;
        int ans = 0;

        while (second < fruits.size()) {
            // 1. Assign 1st fruit type to x
            if (count == 0) {
                x = fruits[second];
                count1++;
                count++;
            } 
            else if (fruits[second] == x) {
                count1++;
            } 
            // 2. Assign 2nd fruit type to y
            else if (count == 1) {
                y = fruits[second];
                count2++;
                count++;
            } 
            else if (fruits[second] == y) {
                count2++;
            } 
            // 3. A 3rd distinct fruit type has arrived
            else {
                count++; // count becomes 3
            }

            // If count reaches 3, shrink window until one fruit type count drops to 0
            if (count == 3) {
                while (count == 3 && first <= second) {
                    if (fruits[first] == x) {
                        count1--;
                        first++;
                        if (count1 == 0) {
                            x = fruits[second]; // Replace x with the 3rd fruit
                            count1 = 1;
                            count--; // count goes back to 2
                        }
                    } 
                    else if (fruits[first] == y) {
                        count2--;
                        first++;
                        if (count2 == 0) {
                            y = fruits[second]; // Replace y with the 3rd fruit
                            count2 = 1;
                            count--; // count goes back to 2
                        }
                    }
                }
            }

            ans = max(ans, count1 + count2);
            second++;
        }

        return ans;
    }
};