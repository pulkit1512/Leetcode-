class Solution {
public:
    int maximum69Number (int num) {
        vector<int>nums;
        while(num>0){
            int no=num%10;
            nums.push_back(no);
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        int n=nums.size();
        bool changed=false;
        for(int i=0;i<n;i++){
            if(!changed&&nums[i]==6){
                nums[i]=9;
                changed=true;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
             ans=ans*10+nums[i];
        }
        return ans;
    }
};