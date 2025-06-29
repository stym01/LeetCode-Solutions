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

    int maxi=-1e9;

    int f(TreeNode*root){
        if(root==NULL) return 0;
        int left=max(f(root->left),0);
        int right=max(f(root->right),0);
        
        maxi=max(maxi,root->val+left+right);
        return max(left,right)+root->val;

    }

    int maxPathSum(TreeNode* root) {
        int x= f(root);
        return maxi;
    }
};