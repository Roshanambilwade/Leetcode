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
   void path(TreeNode* root,int sum,bool &isequal,int &target){
        if(root->left == NULL && root->right == NULL){ // leaf node
            if(sum == target){
                isequal = true;
                
            }
            return;
        }
        if(root->left){
            path(root->left,sum+root->left->val,isequal,target);
        } 
         if(root->right){
            path(root->right,sum+root->right->val,isequal,target);
        } 

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isequal = false;
        if(root==NULL) return false;
        int sum = root->val;
        path(root,sum,isequal,targetSum);
        return isequal;
    }
};