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
                
                
        }
        for(int i=0;i<=max_freq;i++){
            if(s1[i].size()>=length){
               length=s1[i].size();
               index=i;
            }
        }
        return s1[index];


    }
};