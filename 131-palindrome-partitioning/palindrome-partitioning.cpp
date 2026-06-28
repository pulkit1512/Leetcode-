class Solution {
public:
    bool ispalindrome(string s){
        int start=0,end=s.size()-1;
        if(s.size()==1) return true;
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }
    void helper(string s,vector<string>&temp,vector<vector<string>>&ans){
         if(s.size()==0){
            ans.push_back(temp);
         }
         for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);//find the left part of the string and check if it is a palindrome or not 
            if(ispalindrome(part)){
                temp.push_back(part);
                helper(s.substr(i+1),temp,ans);
                temp.pop_back();
            }
         }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        
        helper(s,temp,ans);
        return ans;
    }
};