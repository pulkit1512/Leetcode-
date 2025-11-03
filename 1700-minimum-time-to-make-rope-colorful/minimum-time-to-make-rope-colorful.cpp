class Solution {
public:
 int minCost(string colors, vector<int>& neededTime) {
    int totalTime = 0;
    int prevTime = neededTime[0];

    for (int i = 1; i < colors.size(); ++i) {
        if (colors[i] == colors[i - 1]) {
            totalTime += min(prevTime, neededTime[i]);
            prevTime = max(prevTime, neededTime[i]);
        } else {
            prevTime = neededTime[i];
        }
    }

    return totalTime;
}


};