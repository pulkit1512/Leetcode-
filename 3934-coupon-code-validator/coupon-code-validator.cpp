class Solution {
public:
    bool isValidCode(const string& code) {
    if (code.empty()) return false;
    regex pattern("^[A-Za-z0-9_]+$");
    return regex_match(code, pattern);
}

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<string, string>> valid;
        unordered_map<string, int> order = {{"electronics", 0},
                                            {"grocery", 1},
                                            {"pharmacy", 2},
                                            {"restaurant", 3}};

        for (size_t i = 0; i < code.size(); i++) {
            if (isActive[i] && order.find(businessLine[i]) != order.end() &&
                isValidCode(code[i])) {
                valid.push_back({businessLine[i], code[i]});
            }
        }
       sort(valid.begin(), valid.end(), [&](auto &a, auto &b) {
            if (order[a.first] == order[b.first])
                return a.second < b.second;
            return order[a.first] < order[b.first]; 
       });
        vector<string>ans;
        for(int i=0;i<valid.size();i++){
            ans.push_back(valid[i].second);
        }
        return ans;
    }
};