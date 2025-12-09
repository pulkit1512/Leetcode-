/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode*root,vector<int>&temp){
        if(!root) return 0 ;
        int sum=root->val+helper(root->left,temp)+helper(root->right,temp);
        temp.push_back(sum);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>temp;
        int sum=helper(root,temp);
        unordered_map<int,int>freq;
        for(int i=0;i<temp.size();i++){
            freq[temp[i]]++;
        }
        vector<int>ans;
        int maxi=INT_MIN;
        for(auto it=freq.begin();it!=freq.end();it++){
            maxi=max(maxi,it->second);
        }
        for(auto it=freq.begin();it!=freq.end();it++){
            if(it->second==maxi) ans.push_back(it->first);
        }
        return ans;
    }
};