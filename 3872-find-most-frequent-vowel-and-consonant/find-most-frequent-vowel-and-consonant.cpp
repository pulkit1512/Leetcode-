class Solution {
public:
    int maxFreqSum(string s) {
        int vowel=0;
        int consonant=0;
        unordered_map<char,int>freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        string vowels="aeiou";
        for(auto it=freq.begin();it!=freq.end();it++){
            if(vowels.find(it->first)!=string::npos){
                vowel=max(vowel,it->second);
            }
            else{
                consonant=max(consonant,it->second);
            }
        }
        return vowel+consonant;
    }
};