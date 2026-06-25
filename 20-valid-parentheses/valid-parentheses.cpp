class Solution {
public:
    bool isValid(string s1) {
        stack<char>s;
        if(s1.size()==1) return false ;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='(') s.push(s1[i]);
            else if(s1[i]=='{') s.push(s1[i]);
            else if(s1[i]=='[') s.push(s1[i]);
            if(s.empty()) return false;
            else if(s1[i]==')'){
               if(s.top()=='(') s.pop();
               else return false; 
            }
            else if(s1[i]=='}'){
                if(s.top()=='{') s.pop();
                else return false;
            }
            else if(s1[i]==']'){
                if(s.top()=='[') s.pop();
                else return false;
            }
        }
        if(s.empty()) return true;
        return false;
    }
};