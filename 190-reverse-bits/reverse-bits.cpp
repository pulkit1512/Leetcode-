class Solution {
public:
    int reverseBits(int n) {
        string str="";
        while(n){
            str.push_back(n%2+'0');
            n=n/2;
        }
        // convert into 32 bit 
        while(str.length()<32){
            str.push_back('0');
        }
        int ans=stoi(str,nullptr,2);
        return ans;
    }
};