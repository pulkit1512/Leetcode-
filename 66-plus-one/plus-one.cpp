class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans(n);
        if(digits[n-1]!=9){
            for(int i=0;i<n;i++){
                if(i==n-1){
                    ans[i]=digits[i]+1;
                }
                else{
                ans[i]=digits[i];
                }
            }
        }
        else{
            int carry=1;
            for(int i=n-1;i>=0;i--){
               int sum=digits[i]+carry;
               carry=sum/10;
               ans[i]=sum%10;
            }
            if(carry){
                ans.insert(ans.begin(),carry);
            }
        }
        return ans ;
    }
};