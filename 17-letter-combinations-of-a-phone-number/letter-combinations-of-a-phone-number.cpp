class Solution {
public:
    void helper(string digits,int d_index,string& temp,vector<string>&ans,vector<string>&mapping){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return ;
        }
        string letter = mapping[digits[d_index] - '0'];
        for(int i=0;i<letter.size();i++){
            temp.push_back(letter[i]);
            helper(digits,d_index+1,temp,ans,mapping);
            temp.pop_back();
        }
       
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping = {
            "",    "",    "abc", "def", "ghi", "jkl",
            "mno", "pqrs","tuv", "wxyz"
        };
        vector<string>ans;
        string temp="";
        helper(digits,0,temp,ans,mapping);
        return ans;
    }
};