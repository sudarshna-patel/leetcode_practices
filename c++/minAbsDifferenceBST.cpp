// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    // O(n) time but O(n) memory for array
//     int getMinimumDifference(TreeNode* root) {
//         if (root == NULL) return INT_MIN;
        
//         vector<int> iorder;
//         inorder(root, iorder);
        
//         int min = INT_MAX;
        
//         for(int i = 1; i < iorder.size(); i++) {
//             int diff = iorder[i] - iorder[i-1];
//             if (min > diff)
//                 min = diff;
//         }
        
//         return min;
//     }
    
//     void inorder(TreeNode* root, vector<int>& iorder) {
//         if (root == NULL) return;
        
//         inorder(root->left, iorder);
//         iorder.push_back(root->val);
//         inorder(root->right, iorder);
//     }
    

    // O(n) time and O(1) memore
    int min_diff = INT_MAX;
    TreeNode* prev = NULL;
    
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) return min_diff;
        
        getMinimumDifference(root->left);
        
        if (prev != NULL)
            min_diff = min(min_diff, root->val - prev->val);
        prev = root;
        
        getMinimumDifference(root->right);
        
        return min_diff;
    }
};