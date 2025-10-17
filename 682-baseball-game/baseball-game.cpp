class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> vec;
        int ans = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int sum = vec[vec.size() - 1] + vec[vec.size() - 2];
                vec.push_back(sum);
            }
            else if (operations[i] == "D") {
                vec.push_back(2 * vec.back());
            }
            else if (operations[i] == "C") {
                vec.pop_back();
            }
            else {
                vec.push_back(stoi(operations[i]));
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            ans += vec[i];
        }
        return ans;
    }
};
