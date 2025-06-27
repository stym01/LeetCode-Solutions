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

    void dfs(TreeNode*root,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(target-root->val==0){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }

        temp.push_back(root->val);
        dfs(root->left,target-root->val,temp,ans);
        dfs(root->right,target-root->val,temp,ans);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(root,targetSum,temp,ans);
        return ans;
    }
};