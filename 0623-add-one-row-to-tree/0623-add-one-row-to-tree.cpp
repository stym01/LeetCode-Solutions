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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode*nn=new TreeNode(val,root,NULL);
            return nn;
        }
        int cnt=1;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=0;
        while(!q.empty()){
            int size=q.size();
            if(cnt==depth-1) flag=1;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(flag){
                    
                    TreeNode*nn=new TreeNode(val,temp->left,NULL);
                    TreeNode*nn2=new TreeNode(val,NULL,temp->right);
                    temp->left=nn;
                    temp->right=nn2;
                }
                else{
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            if(flag) return root;
            cnt++;
        }
        return root;
    }
};