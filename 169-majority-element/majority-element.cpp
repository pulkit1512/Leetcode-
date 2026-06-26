class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {   
        int n = nums.size(); 

        sort(nums.begin(), nums.end());
        
        int ans = 1; 
        for (int i = 0; i < n - 1; i++)
         { 
            if (nums[i] == nums[i + 1]) 
            { 
                ans++;  
            }
             else
              {
                ans = 1; 
            }

            if (ans > n / 2) { 
                return nums[i]; 
            }
        } 
        
        return nums[0];
    }
};