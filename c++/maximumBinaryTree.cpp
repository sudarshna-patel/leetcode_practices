// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& nums, int low, int high) {
        int max = nums[low], max_index = -1;
        
        for(int i = low; i <= high; i++)
            if (max <= nums[i]) {
                max = nums[i];
                max_index = i;
            }
        
        if (max_index == -1) return NULL;
        TreeNode* temp = new TreeNode(max);
        temp->left = buildTree(nums, low, max_index-1);
        temp->right = buildTree(nums, max_index+1, high);
        return temp;
    }
};