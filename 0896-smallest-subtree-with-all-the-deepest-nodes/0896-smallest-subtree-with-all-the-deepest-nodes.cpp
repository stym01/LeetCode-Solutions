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

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*,TreeNode*>parent;
        parent[root]=NULL;
        int maxi=0;
        par(root,0,maxi,parent);

        queue<TreeNode*>q;
        q.push(root);
        int depth=0;
        vector<TreeNode*>childs;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(depth==maxi-1){
                    if(temp->left==NULL && temp->right==NULL){
                        continue;
                    }
                    else{
                        childs.push_back(temp);
                    }
                }
                else{
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            depth++;
        }
        if(childs.size()==0) return root;
        if(childs.size()==1) {
            TreeNode*first=childs[0];
            if(first->left!=NULL && first->right!=NULL)
                return childs[0];
            else if(first->left) return first->left;
            return first->right;
        }

        while(1){
            bool flag=0;
            for(int i=0;i<childs.size();i++){
                if(childs[i]!=childs[0]){
                    flag=1;
                    break;
                }
            }
            if(flag==0) return childs[0];
            for(int i=0;i<childs.size();i++) {
                childs[i]=parent[childs[i]];
            }
        }
        return root;
    }
};