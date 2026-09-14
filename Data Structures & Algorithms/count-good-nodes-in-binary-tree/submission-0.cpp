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
 
    int solve(TreeNode* root,int maxSoFar) {
        
        if(root == nullptr) return 0;

        int count = 0;

        if(root->val >= maxSoFar) count++;

        //update maximum
        int newmax = max(maxSoFar,root->val);

        count += solve(root->left,newmax);
        count += solve(root->right,newmax);

        return count;
        
    }

    int goodNodes(TreeNode *root){
        if(root == nullptr) return 0;

        return solve(root,root->val);
    }
};
