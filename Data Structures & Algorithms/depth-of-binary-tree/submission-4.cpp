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

/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);

        return 1 + max(leftdepth,rightdepth);

    }
};
*/

class Solution{

    public:
    int maxDepth(TreeNode *root){
        if(root == nullptr) return 0;

        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int size = q.size();
            depth++;

            for(int i =0 ; i<size ;i++){ // loop ensures u process 1 full level of the tree during each iteration of while loop i.e  level order traversal
                TreeNode * node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return depth;
    }
};