class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>m;
        int max_freq=INT_MIN;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            max_freq=max(max_freq,m[s[i]]);
        }

        vector<string>s1(max_freq+1,"");
        int length=0;
        int index=0;
        for(auto it=m.begin();it!=m.end();it++){
                s1[it->second]+=it->first;
                
                if(s1[it->second].size()>length){
                    length=s1[it->second].size();
                    index=it->second;
                }
                if(s1[it->second].size()==length){
                   index=max(index,it->second);
                }
        }
        return s1[index];


    }
};