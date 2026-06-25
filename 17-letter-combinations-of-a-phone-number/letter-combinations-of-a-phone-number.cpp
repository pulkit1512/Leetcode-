class Solution {
public:
    void helper(string digits,int d_index,int l_index,string temp,vector<string>&ans,vector<string>&mapping){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return ;
        }
        string letter = mapping[digits[d_index] - '0'];

        if(l_index==letter.size()) return ;
        helper(digits,d_index+1,0,temp+letter[l_index],ans,mapping);
        helper(digits,d_index,l_index+1,temp,ans,mapping);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping = {
            "",    "",    "abc", "def", "ghi", "jkl",
            "mno", "pqrs","tuv", "wxyz"
        };
        vector<string>ans;
        helper(digits,0,0,"",ans,mapping);
        return ans;
    }
};