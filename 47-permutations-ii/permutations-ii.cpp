class Solution {
public:
    void helper(vector<int>& arr, int index, vector<vector<int>>& ans) {
        if(index == arr.size()) {
            ans.push_back(arr);
            return;
        }
        vector<bool>use(21,0);
        for(int i = index; i < arr.size(); i++) {
          if(use[arr[i]+10]==0){
            swap(arr[i],arr[index]);
            helper(arr,index+1,ans);
            swap(arr[i],arr[index]);
            use[arr[i]+10]=1;
          }
           
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};
