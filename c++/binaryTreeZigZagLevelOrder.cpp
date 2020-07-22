// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == NULL) return res;
        
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = curr->val;
                
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            // after this level
            leftToRight = !leftToRight;
            res.push_back(row);
        }
        
        return res;
    }
};