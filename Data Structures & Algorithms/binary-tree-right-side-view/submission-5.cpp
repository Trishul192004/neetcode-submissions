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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(root == NULL) return {};
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>level;

            for(int i =0; i < n ;i++){
                TreeNode * it = q.front();
                q.pop();
                level.push_back(it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);

            }

            for(int i = 0; i<level.size();i++){
                if(i ==level.size() -1 ) ans.push_back(level[i]);
                else continue;
            }
        }

        return ans;
    }
};
