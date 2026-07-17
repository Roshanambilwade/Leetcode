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
    int isbal(TreeNode* root,bool &isequal){
        if(root == NULL) return 0;
       int lefth = isbal(root->left,isequal);
        int righth = isbal(root->right,isequal);
        if(abs(lefth - righth) >1){
            isequal = false;
            
        }
        return max(lefth,righth)+1;

    }
    bool isBalanced(TreeNode* root) {
        bool isequal = true;
        isbal(root,isequal);
        return isequal;
    }
};