// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res (2, -1);
        
        if (nums.size() == 0) return res;
        
        int left = 0, right = nums.size() - 1, mid;
        
        // searching for left index
        while (left < right) {
            mid = left + (right - left)/2;
            
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        if (nums[left] != target)
            return res;
        else
            res[0] = left;
        
        // no need to set left here
        // searching for right index
        right = nums.size()-1;
        while (left < right) {
            mid = left + (right - left)/2 + 1; // making it right biased
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        res[1] = right;
        return res;
    }
};