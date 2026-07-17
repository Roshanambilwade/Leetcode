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
    bool ans = true;
    void same(TreeNode* p, TreeNode* q){
         if(p == NULL && q == NULL){
            return;
        }
        if(p==NULL || q == NULL){
            ans = false;
            return;
        }
        if(p->val != q->val){
            ans = false;
            return;
        }
       
        same(p->left,q->left);
        same(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        same(p,q);
        return ans;
    }
};