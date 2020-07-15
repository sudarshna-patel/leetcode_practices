// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) return -1;
        if (size == 1) return nums[0];
        
        int left = 0, right = size-1, rotated;
        while(left <= right) {
            rotated = left + (right-left)/2;
            if (nums[rotated] > nums[rotated+1]) {
                break;
            } else {
                if (nums[rotated] > nums[size-1])
                    left = rotated + 1;
                else
                    right = rotated - 1;
            }
        }
        if (rotated == 0 && nums[rotated] < nums[size-1])
            return nums[rotated];
        return nums[rotated+1];
    }
};