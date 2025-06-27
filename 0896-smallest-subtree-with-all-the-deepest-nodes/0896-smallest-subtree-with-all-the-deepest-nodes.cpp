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

    void par(TreeNode*root,int d,int &maxi,map<TreeNode*,TreeNode*>&parent){
        if(root==NULL) return;
        maxi=max(d,maxi);
        if(root->left) {
            parent[root->left]=root;
            par(root->left,d+1,maxi,parent);
        }
        if(root->right) {
            parent[root->right]=root;
            par(root->right,d+1,maxi,parent);
        }

    }

    TreeNode*f(TreeNode*root,int d,int maxi){
        if(root==NULL || d==maxi) return root;
        TreeNode*left=f(root->left,d+1,maxi);
        TreeNode*right=f(root->right,d+1,maxi);
        if(left!=NULL && right!=NULL) return root;
        if(left!=NULL) return left;
        if(right!=NULL) return right;
        return NULL;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*,TreeNode*>parent;
        parent[root]=NULL;
        int maxi=0;
        par(root,0,maxi,parent);

        return f(root,0,maxi);
    }
};